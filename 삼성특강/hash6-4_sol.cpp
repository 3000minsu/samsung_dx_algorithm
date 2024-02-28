#include <iostream>
#include <cstring>
using namespace std;
typedef struct _Node {
	struct _Node* next;
	int idx;
}node;
node heads[17580];
node nodes[100000];
int node_cnt = 0;
char ori[50002];
int len;
int h[50002];
int arr[50002];
int res[50002];

node* get_newnode(int id)
{
	nodes[node_cnt].next = NULL;
	nodes[node_cnt].idx = id;
	return &nodes[node_cnt++];
}

void insert(int id, int hash)
{
	node* temp;
	temp = get_newnode(id);
	temp->next = heads[hash].next;
	heads[hash].next = temp;
}

void merges(int left, int right) {
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (arr[i] > arr[j]) {
			res[k++] = arr[j++];
		}
		// 양쪽 리스트에서 최솟값을 비교했는데 오른쪽 리스트가 더 컸을 경우
		// 그대로 왼쪽 리스트의 최솟값이 결과배열에 내려오면 됩니다.
		else {
			res[k++] = arr[i++];
		}
	}

	// 오른쪽 리스트에 아직 결과배열에 들어가지 못한 값이 있으면 그대로 넣어줍니다.
	if (i > mid) {
		while (j <= right) {
			res[k++] = arr[j++];
		}
	}
	else { // 그림의 (6)번 과정
		while (i <= mid) {
			res[k++] = arr[i++];
		}
	}

	// 다시 원래 배열에 옮겨담는 작업
	for (int a = left; a <= right; a++) {
		arr[a] = res[a];
	}
}

void partition(int left, int right) {
	int mid;
	// 두개로 분할하고, 병합하는 과정
	// 병합 함수 merges를 보면 알 수 있듯이, while문 등으로 정렬하면서 병합하게 된다.
	if (left < right) {
		mid = (left + right) / 2;
		partition(left, mid);
		partition(mid + 1, right);
		merges(left, right);
	}
}
/*
void quickSort(int first, int last)
{
	int pivot;
	int i;
	int j;
	int temp;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;

		while (i < j)
		{
			while (arr[i] <= arr[pivot] && i < last)
			{
				i++;
			}
			while (arr[j] > arr[pivot])
			{
				j--;
			}
			if (i < j)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

		temp = arr[pivot];
		arr[pivot] = arr[j];
		arr[j] = temp;

		quickSort(first, j - 1);
		quickSort(j + 1, last);
	}
}*/


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
	node* t, * go, * p;
	int pre = -10, cnt = 0, temp, o, ch, c = 0, i;
	int hash_a = make_hash(string_A);
	if (heads[hash_a].next == NULL)
		return 0;
	else
	{
		go = heads[hash_a].next;
		while (go != NULL)
		{
			arr[c++] = go->idx;
			go = go->next;
		}
		partition(0, c-1);
		go = heads[hash_a].next;
		for (int k = 0; k < c; k++)
		{
			go->idx = arr[k];
			go = go->next;
		}
		
		for(int k=0; k<c; k++)
		{
			i = arr[k];
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
							h[i + j] = temp;//해시값 넣기
							insert(i + j, temp);
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
}