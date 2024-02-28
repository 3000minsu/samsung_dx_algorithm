#include <bits/stdc++.h>
using namespace std;
typedef struct _Node {
    int data;
    int cnt;
    struct _Node* left;
    struct _Node* right;
}node;
node tree[10001];
int c, d, cnt=0, ans, ch=0;
int fi(node* n)
{
    if (n == NULL)
        return 0;
    n->cnt += fi(n->left);
    if (ch)
        return 0;
    n->cnt += fi(n->right);
    if (ch)
        return 0;
    if (n->cnt == 2)
    {
        ch = 1;
        ans = n->data;
    }
    return n->cnt;
}
void co(node* n)
{
    if (n != NULL)
        cnt++;
    else
        return;
    co(n->left);
    co(n->right);
}
int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_case;
    int T, a, b;
    int temp, temp2;
    freopen("input (4).txt", "r", stdin);
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> a >> b >> c >> d;
        for (int i = 1; i <= a; i++)
        {
            tree[i].left = NULL;
            tree[i].right = NULL;
            tree[i].data = i;
            if (i == c || i == d)
                tree[i].cnt = 1;
            else
                tree[i].cnt = 0;
        }
        for (int i = 0; i < b; i++)
        {
            cin >> temp >> temp2;
            if(tree[temp].left==NULL)
                tree[temp].left = &tree[temp2];
            else if (tree[temp].right == NULL)
                tree[temp].right = &tree[temp2];
        }
        ch = 0;
        cnt = 0;
        fi(&tree[1]);
        co(&tree[ans]);
        cout << "#" << test_case << " ";
        cout << ans << " "<<cnt<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}