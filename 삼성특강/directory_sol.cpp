#include <bits/stdc++.h>
#define NAME_MAXLEN 6
#define PATH_MAXLEN 1999
using namespace std;
typedef struct _Node {
	int hash;
	struct _Node* parent;
	int child_cnt = 0;
	int child_idx = 0;
	struct _Node* child[1000];
}node;
node root;
node nodes[100000];
int node_cnt = 0;

int make_hash(char name[NAME_MAXLEN + 1])
{
	int i = 0, hash=0, power=1;
	while (name[i] != '\0')
	{
		hash += (name[i]-96) * power;
		i++;
		power *= 27;
	}
	return hash;
}

node* node_find(char path[PATH_MAXLEN + 1])
{
	node* now=&root;
	char temp[NAME_MAXLEN + 1];
	int i=1, t=0, h;
	while (path[i]!='\0')
	{
		while (path[i] != '/')
		{
			temp[t] = path[i];
			i++;
			t++;
		}
		temp[t] = '\0';
		h = make_hash(temp);
		for (int k=0; k<now->child_idx; k++)
		{
			if (now->child[k]!=NULL&&now->child[k]->hash == h)
			{
				now = now->child[k];
				break;
			}
		}
		t = 0;
		i++;
	}
	return now;
}

node* get_newnode(int h, node* p)
{
	nodes[node_cnt].hash = h;
	nodes[node_cnt].parent = p;
	nodes[node_cnt].child_cnt = 0;
	nodes[node_cnt].child_idx = 0;
	return &nodes[node_cnt++];
}

void update_child_cnt(node* now, int diff)
{
	node* go = now->parent;
	while (go != NULL)
	{
		go->child_cnt += diff;
		go = go->parent;
	}
}

void init(int n) {
	node_cnt = 0;
	root.hash = -1;
	root.parent = NULL;
	root.child_cnt = 0;
	root.child_idx = 0;
}

void cmd_mkdir(char path[PATH_MAXLEN + 1], char name[NAME_MAXLEN + 1]) {
	int h = make_hash(name);
	node* go = node_find(path);
	node* n = get_newnode(h, go);
	go->child[go->child_idx++] = n;
	update_child_cnt(n, 1);
}

void cmd_rm(char path[PATH_MAXLEN + 1]) {
	node* go = node_find(path);
	node* p = go->parent;
	update_child_cnt(go, -(go->child_cnt + 1));
	for (int i = 0; i < p->child_idx; i++)
	{
		if (p->child[i]!=NULL&&p->child[i]->hash == go->hash)
		{
			p->child[i] = NULL;
			break;
		}
	}
	go->parent = NULL;
}

void rec_cp(node* pa, node* now)
{
	int k = 0;
	for (int i = 0; i < now->child_idx; i++)
	{
		if (now->child[i] != NULL)
		{
			//pa->child[k] = now->child[i];
			node* temp = get_newnode(now->child[i]->hash, pa);
			temp->child_cnt = now->child[i]->child_cnt;
			pa->child[k] = temp;
			k++;
			rec_cp(temp, now->child[i]);
		}
	}
	pa->child_idx = k;
}

void cmd_cp(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
	int k=0;
	node* pa = node_find(dstPath);
	node* ch = node_find(srcPath);
	node* n = get_newnode(ch->hash, pa);
	/*for (int i = 0; i < ch->child_idx; i++)
	{
		if (ch->child[i] != NULL)
		{
			n->child[k] = ch->child[i];
			k++;
		}
	}
	n->child_idx = k;*/
	pa->child[pa->child_idx++] = n;
	n->child_cnt = ch->child_cnt;
	update_child_cnt(n, ch->child_cnt+1);
	rec_cp(n, ch);
	//cnt는 따로해주자
}

//cp가 null?
void cmd_mv(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
	node* p = node_find(dstPath);
	node* c = node_find(srcPath);
	node* cp = c->parent;
	update_child_cnt(c, -(c->child_cnt + 1));
	for (int i = 0; i < cp->child_idx; i++)
	{
		if (cp->child[i]!=NULL&&cp->child[i]->hash == c->hash)
		{
			cp->child[i] = NULL;
			break;
		}
	}
	c->parent = p;
	p->child[p->child_idx++] = c;
	update_child_cnt(c, (c->child_cnt + 1));
}

int cmd_find(char path[PATH_MAXLEN + 1]) {
	node* go = node_find(path);
	//printf("%d\n", go->child_cnt);
	return go->child_cnt;
}