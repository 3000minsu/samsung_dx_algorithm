#include<iostream>
using namespace std;
char a[1002];
char b[1002];
int pre[1002] = { 0 };
int now[1002];
int ma(int a, int b)
{
	return a > b ? a : b;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> a;
		cin >> b;
		now[0] = 0;
		for (int i = 0; i < strlen(a); i++)
		{
			for (int j = 0; j < strlen(b); j++)
			{
				if (a[i] == b[j])
				{
					now[j + 1] = pre[j] + 1;
				}
				else
				{
					now[j + 1] = ma(pre[j + 1], now[j]);
				}
			}
			for (int j = 0; j <= strlen(b); j++)
			{
				pre[j] = now[j];
			}
		}
		cout << "#" << test_case << " " << now[strlen(b)] << "\n";
		memset(pre, 0, sizeof(pre));
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}