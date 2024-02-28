#include <bits/stdc++.h>
#define ma 1000000007
using namespace std;
char temp[10001];
long long pre[16] = { 0 };
long long now[16] = { 0 };
int ch_char(int i)
{
	if (temp[i] == 'A')
		return 0;
	else if (temp[i] == 'B')
		return 1;
	else if (temp[i] == 'C')
		return 2;
	else if (temp[i] == 'D')
		return 3;
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test_case;
	int T, i=0, k;
	long long ans = 0;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> temp;
		k = ch_char(0);
		for (int j = 1; j <= 15; j++)
		{
			if ((j & (1 << k)) && (j & (1 << 0)))
				pre[j] = 1;
		}
		i++;
		while (temp[i] != '\0')
		{
			k = ch_char(i);
			for (int j = 1; j <= 15; j++)
			{
				if (j & (1 << k))
				{
					for (int a = 1; a <= 15; a++)
					{
						if (j & a)
							now[j] += pre[a]%ma;
					}
				}
			}
			for (int j = 1; j <= 15; j++)
			{
				pre[j] = now[j];
				now[j] = 0;
			}
			i++;
		}
		for (int j = 1; j <= 15; j++)
			ans += pre[j]%ma;
		ans %= ma;
		cout << "#" << test_case << " " << ans << "\n";
		i = 0;
		ans = 0;
		for (int j = 1; j <= 15; j++)
		{
			now[j] = 0;
			pre[j] = 0;
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}