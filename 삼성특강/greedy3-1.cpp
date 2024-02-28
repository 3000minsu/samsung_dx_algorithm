#include <bits/stdc++.h>
using namespace std;
int n, ma=0, k, ch=0;
char tt[8];
void dfs(int cnt)
{
	if (cnt == n)
	{
		if (ma < atoi(tt))
			ma = atoi(tt);
		if (is_sorted(tt, tt + k, greater<int>()))
			ch = 1;
		return;
	}
	for (int j = 0; j < k - 1; j++)
	{
		for (int y = j + 1; y < k; y++)
		{
			swap(tt[j], tt[y]);
			if (is_sorted(tt, tt + k, greater<int>()))
			{
				if ((n - cnt) % 2 == 1)
				{
					ma = atoi(tt);
					ch = 1;
					return;
				}
				else
				{
					swap(tt[k - 2], tt[k - 1]);
					ma = atoi(tt);
					ch = 1;
					return;
				}
			}
			dfs(cnt + 1);
			if (ch == 1)
				return;
			swap(tt[j], tt[y]);
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	char nu[8];
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		ma = 0;
		ch = 0;
		cin >> nu;
		cin >> n;
		k = strlen(nu);
		strcpy(tt, nu);
		dfs(0);
		cout << "#" << test_case << " " << ma << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}