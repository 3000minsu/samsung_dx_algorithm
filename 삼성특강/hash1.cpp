#include <bits/stdc++.h>
#define maxl 51
#define maxn 200003
using namespace std;
typedef struct _Node {
	char str[maxl];
	struct _Node* next=NULL;
}node;
int node_count = 0, cnt=0;
node nodes[100001];
node hash_table[maxn];
node* new_node(char str[maxl]) {
	strcpy(nodes[node_count].str, str);
	nodes[node_count].next = nullptr;
	return &nodes[node_count++];
}
int make_hash(char* temp)
{
	int hash = 5381;
	while (*temp != '\0')
	{
		hash= (((hash << 5) + hash) + *temp)%maxn;
		temp++;
	}
	return hash;
}
void inser(char* temp)
{
	int h= make_hash(temp);
	node* go = &hash_table[h];
	while (go->next != NULL)
	{
		go = go->next;
	}
	go->next = new_node(temp);
}
void fin(char* temp)
{
	int h = make_hash(temp);
	if (hash_table[h].next == NULL)
		return;
	else
	{
		node* go = hash_table[h].next;
		while (go != NULL)
		{
			if (strcmp(go->str, temp) == 0)
			{
				cnt++;
				return;
			}
			go = go->next;
		}
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T, a, b;
	char temp[maxl];
	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> a >> b;
		for (int i = 0; i < a; i++)
		{
			cin >> temp;
			inser(temp);
		}
		for (int i = 0; i < b; i++)
		{
			cin >> temp;
			fin(temp);
		}

		cout << "#" << test_case << " " << cnt << "\n";
		cnt = 0;
		node_count = 0;
		memset(hash_table, 0, sizeof(hash_table));
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}