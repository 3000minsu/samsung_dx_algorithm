#include <bits/stdc++.h>
using namespace std;
typedef struct _Node {
    int data;
    struct _Node* left;
    struct _Node* right;
}node;
node tree[1001];
int n;
node* cal(node* n)
{
    if (n->left == NULL && n->right == NULL)
    {
        return n;
    }
    else
    {
        n->left = cal(n->left);
        n->right = cal(n->right);
        if (n->data == -1)
            n->data = n->left->data + n->right->data;
        else if (n->data == -2)
            n->data = n->left->data - n->right->data;
        else if (n->data == -3)
            n->data = n->left->data * n->right->data;
        else if (n->data == -4)
            n->data = n->left->data / n->right->data;
        return n;
    }
}
int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_case;
    int T, a, b;
    freopen("input (3).txt", "r", stdin);
    //cin >> T;
    string temp;
    for (test_case = 1; test_case <= 10; ++test_case)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> T;
            cin >> temp;
            if (temp[0] == '-' || temp[0] == '+' || temp[0] == '*' || temp[0] == '/')
            {
                cin >> a >> b;
                if (temp[0] == '+')
                    tree[T].data = -1;
                else if(temp[0]=='-')
                    tree[T].data = -2;
                else if (temp[0] == '*')
                    tree[T].data = -3;
                else if (temp[0] == '/')
                    tree[T].data = -4;
                tree[T].left = &tree[a];
                tree[T].right = &tree[b];
            }
            else
            {
                tree[T].data = atoi(&temp[0]);
                tree[T].left = NULL;
                tree[T].right = NULL;
            }
            temp.clear();
        }
        cal(&tree[1]);
        cout << "#" << test_case << " ";
        cout << tree[1].data<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}