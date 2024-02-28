#include<iostream>
using namespace std;
int pre[1002] = { 0 };
int now[1002] = { 0 };
int main(int argc, char** argv)
{
	int test_case;
	int T, n, k, a, b;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n >> k;
		cin >> a >> b;
		for (int i = a; i <= k; i++)
		{
			pre[i] = b;
			now[i] = b;
		}
		for (int i = 0; i < n-1; i++)
		{
			cin >> a >> b;
			for (int j = 0; j <= k - a; j++)
			{
				if (pre[j + a] < b + pre[j])
					now[j + a] = b + pre[j];
			}
			for (int j = 0; j <= k; j++)
			{
				pre[j] = now[j];
			}
		}
		cout << "#" << test_case << " " << now[k] << "\n";
		memset(pre, 0, sizeof(pre));
		memset(now, 0, sizeof(now));
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}