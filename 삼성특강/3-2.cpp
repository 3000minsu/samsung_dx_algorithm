#include <bits/stdc++.h>
using namespace std;
bool tree[201] = { false };
int n, c=0;
void check_tree(int in)
{
    if (in <= n)
    {
        if (in * 2 <= n || in * 2 + 1 <= n)
        {
            if (tree[in] == false)
            {
                c = 1;
                return;
            }
        }
        if (in * 2 > n && in * 2 + 1 > n)
        {
            if (tree[in] == true)
            {
                c = 1; 
            }
            return;
        }
        check_tree(in * 2);
        if (c == 1)
            return;
        check_tree(in * 2 + 1);
        if (c == 1)
            return;

    }
}
int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_case;
    int T;
    freopen("input (2).txt", "r", stdin);
    //cin >> T;
    string temp;
    for (test_case = 1; test_case <= 10; ++test_case)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> T;
            getline(cin, temp);
            if (temp[1] == '-' || temp[1] == '+' || temp[1] == '*' || temp[1] == '/')
                tree[T] = true;
            else
                tree[T] = false;
            temp.clear();
        }
        cout << "#" << test_case << " ";
        if (n % 2 == 0)
            cout << "0\n";
        else
        {
            check_tree(1);
            if(c==1)
                cout << "0\n";
            else
                cout << "1\n";
        }
        c = 0;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}