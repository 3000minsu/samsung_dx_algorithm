#include <malloc.h>
typedef struct _Node {
	int data;
	int id;
	struct _Node* next;
}node;
node nodes[100001];
node* head = (node*)malloc(sizeof(node));
int cnt = 0, nodecnt = 0;
node* newnode(int data, int uid)
{
	nodes[nodecnt].data = data;
	nodes[nodecnt].id = uid;
	nodes[nodecnt].next = NULL;
	return &nodes[nodecnt++];
}

void init()
{
	cnt = 0;
	nodecnt = 0;
	head->next = NULL;
}

void addUser(int uID, int height)
{
	node* go = head->next;
	node* pre = head;
	node* temp;
	int i = 0;
	/*if (go == NULL)
	{
		temp = newnode(height, uID);
		go = temp;
		temp->next = NULL;
		return;
	}*/
	while (i < 10)
	{
		if (go == NULL||(go->data < height)|| (go->data == height && uID < go->id))
		{
			temp = newnode(height, uID);
			temp->next = pre->next;
			pre->next = temp;
			break;
		}
		i++;
		pre = go;
		go = go->next;
	}
}

int getTop10(int result[10])
{
	node* go = head->next;
	int i = 0;
	while (i < 10&&go!=NULL)
	{
		result[i] = go->id;
		go = go->next;
		i++;
	}
	return i;
}