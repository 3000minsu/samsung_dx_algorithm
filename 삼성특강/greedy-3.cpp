#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T, n, k, ch=0, temp, ans, tp;
	char nu[8];
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> nu;
		cin >> n;
		ch = 0;
		k = strlen(nu);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < k - 1; j++)
			{
				temp = nu[j];
				for (int y = j + 1; y < k; y++)
				{
					if (temp < nu[y])
					{
						ch = 1;
						tp = y;
						temp = nu[y];
					}
				}
				if (ch == 1)
				{
					swap(nu[tp], nu[j]);
					break;
				}
			}
			if (ch == 0)
			{
				swap(nu[k - 1], nu[k - 2]);
			}	
			ch = 0;
		}
		ans = atoi(nu);
		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}