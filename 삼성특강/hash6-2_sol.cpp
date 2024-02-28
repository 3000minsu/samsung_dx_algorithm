#include <iostream>
#include <cstring>
using namespace std;
typedef struct _Node {
	struct _Node* next;
	//struct _Node* prev;
	int idx;
}node;
node heads[17580];
node nodes[100000];
int node_cnt = 0;
char ori[50002];
int len;
int h[50002];
int arr[50002];
int arr2[50002];

node* get_newnode(int id)
{
	nodes[node_cnt].next = NULL;
	//nodes[node_cnt].prev = NULL;
	nodes[node_cnt].idx = id;
	return &nodes[node_cnt++];
}

void insert(int id, int hash)
{
	node* temp;
	temp = get_newnode(id);
	temp->next = heads[hash].next;
	//if (heads[hash].next != NULL)
		//heads[hash].next->prev = temp;
	heads[hash].next = temp;
	//temp->prev = &heads[hash];
}

node* sortedMerge(node* a, node* b)
{
	if (a == NULL) {
		return b;
	}

	else if (b == NULL) {
		return a;
	}

	node* result = NULL;

	// `a` 또는 `b`를 선택하고 반복합니다.
	if (a->idx <= b->idx)
	{
		result = a;
		result->next = sortedMerge(a->next, b);
	}
	else {
		result = b;
		result->next = sortedMerge(a, b->next);
	}

	return result;
}

void frontBackSplit(node* source, node** frontRef,
	node** backRef)
{
	
	if (source == NULL || source->next == NULL)
	{
		*frontRef = source;
		*backRef = NULL;
		return;
	}

	node* slow = source;
	node* fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}


void mergesort(node** head)
{
	
	if (*head == NULL || (*head)->next == NULL) {
		return;
	}

	node* a;
	node* b;
	frontBackSplit(*head, &a, &b);
	mergesort(&a);
	mergesort(&b);

	*head = sortedMerge(a, b);
}

int make_hash(char str[])
{
	return str[0] - 97 + (str[1] - 97) * 26 + (str[2] - 97) * 26 * 26;
}



void init(int N, char init_string[])
{
	int hash;
	node* temp;
	node_cnt = 0;
	memset(heads, 0, sizeof heads);
	/*for (int i = 0; i < 17580; i++)
	{
		heads[i].next = NULL;
		//heads[i].prev = NULL;
	}*/
	memset(h, -1, sizeof h);
	strcpy(ori, init_string);
	len = N;
	for (int i = 0; i <= N - 3; i++)
	{
		hash = make_hash(&ori[i]);
		insert(i, hash);
		h[i] = hash;
	}
}

int change(char string_A[], char string_B[])
{
	//list<int>::iterator it;
	node* t, *go, *p;
	int pre = -10, cnt = 0, temp, o, ch, c=0, i;
	int hash_a = make_hash(string_A);
	if (heads[hash_a].next==NULL)
		return 0;
	else
	{
		t = &heads[hash_a];
		mergesort(&t);
		//v[hash_a].sort();
		go = heads[hash_a].next;
		/*while (go != NULL)
		{
			arr[c++] = go->idx;
			go = go->next;
		}*/
		//vector<int> vt(v[hash_a].begin(), v[hash_a].end());
		//for (set<int>::iterator i=v[hash_a].begin(); i!= v[hash_a].end();i++)
		while(go!=NULL)
		{
			i=go->idx;
			
			if (i >= pre + 3)
			{
				strncpy(&ori[i], string_B, 3);
				for (int j = -2; j <= 2; j++)
				{
					if (i + j >= 0 && i + j <= len - 3)
					{
						ch = 0;
						o = h[i + j];
						temp = make_hash(&ori[i + j]);//새로운 거 해시값
						if (o != temp)
						{
							if (temp != hash_a)
							{
								h[i + j] = temp;//해시값 넣기
								insert(i + j, temp);
							}
							else
							{


							}


							go = heads[o].next;
							p = &heads[o];
							while (go != NULL)
							{
								if (go->idx == i + j)
								{
									ch = 1;
									break;
								}
								p = go;
								go = go->next;
							}
							if (ch == 1)
							{
								p->next = go->next;
								go->next = NULL;
								//go->prev = NULL;
								//it = v[o].erase(it);
							}
						}
					}
				}
				pre = i;
				cnt++;
			}
		}
	}

	return cnt;
}

void result(char ret[])
{
	strcpy(ret, ori);
	/*for (int i = 0; i < len; i++)
		ret[i] = ori[i];*/

}