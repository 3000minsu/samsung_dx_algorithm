
#include <bits/stdc++.h>
using namespace std;
typedef struct _Node {
    struct _Node* next;
    struct _Node* prev;
    int idx;
}node;
//unordered_multimap<string, int> m;
node heads[17580];
node nodes[100000];
int node_cnt = 0;
char ori[50002];
int len;
vector<list<int>> v;
int h[50002];

node* get_newnode(int id)
{
    nodes[node_cnt].next = NULL;
    nodes[node_cnt].prev = NULL;
    nodes[node_cnt].idx = id;
    return &nodes[node_cnt++];
}

void insert(int id, int hash)
{
    node* temp;
    temp = get_newnode(id);
    temp->next = heads[hash].next;
    if (heads[hash].next != NULL)
        heads[hash].next->prev = temp;
    heads[hash].next = temp;
    temp->prev = &heads[hash];
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

/*
    주어진 목록의 노드를 앞과 뒤 반으로 나눕니다.
    참조 매개변수를 사용하여 두 목록을 반환합니다.
    길이가 홀수이면 추가 노드가 맨 앞 목록에 있어야 합니다.
    빠른/느린 포인터 전략을 사용합니다.
*/
void frontBackSplit(node* source, node** frontRef,
    node** backRef)
{
    // 길이가 2보다 작으면 별도로 처리
    if (source == NULL || source->next == NULL)
    {
        *frontRef = source;
        *backRef = NULL;
        return;
    }

    node* slow = source;
    node* fast = source->next;

    // 2개의 노드만큼 `fast`를 전진시키고 단일 노드로 `slow`를 전진시킵니다.
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // `slow`는 목록의 중간 지점 앞에 있으므로 두 개로 나눕니다.
    // 그 시점에서.
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

// 병합 배열 알고리즘을 사용하여 주어진 연결된 목록을 배열합니다.
void mergesort(node** head)
{
    // 기본 케이스 — 길이 0 또는 1
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    node* a;
    node* b;

    // `head`를 `a`와 `b` 하위 목록으로 분할
    frontBackSplit(*head, &a, &b);

    // 하위 목록을 재귀적으로적으로 정렬
    mergesort(&a);
    mergesort(&b);

    // 답변 = 두 개의 정렬된 목록 병합
    *head = sortedMerge(a, b);
}
int main()
{
    node* temp = &heads[0];
    insert(4, 0);
    insert(3, 0);
    insert(5, 0);
    insert(1000, 0);
    insert(100, 0);
    mergesort(&temp);
    node* go = heads[0].next;
    while (go != NULL)
    {
        printf("%d ", go->idx);
        go = go->next;
    }

    return 0;
}