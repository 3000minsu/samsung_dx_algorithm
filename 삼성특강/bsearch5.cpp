#include <bits/stdc++.h>
#define inf 200000000
using namespace std;
int cow[500001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, c1, c2, temp, cnt=0;
	int T, in1, in2, d1, d2, mi;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		mi = inf;
		cnt = 0;
		cin >> n>>m;
		cin >> c1 >> c2;
		for (int i = 0; i < n; i++)
			cin >> cow[i];
		sort(cow, cow + n);
		for (int i = 0; i < m; i++)
		{
			cin >> temp;
			in1=lower_bound(cow, cow + n, temp)-cow;
			if (in1 > 0)
				in2 = in1 - 1;
			else
				in2 = 0;
			d1 = abs(cow[in1] - temp);
			d2 = abs(cow[in2] - temp);
			if (d1 > d2)
			{
				if (d2 < mi)
				{
					mi = d2;
					cnt = 1;
				}
				else if (d2 == mi)
					cnt++;
			}
			else if (d1 < d2)
			{
				if (d1 < mi)
				{
					mi = d1;
					cnt = 1;
				}
				else if (d1 == mi)
					cnt++;
			}
			else if (d1== d2)
			{
				if (d2 == 0)
				{
					if (d1 < mi)
					{
						mi = d1;
						cnt = 1;
					}
					else if (d1 == mi)
						cnt++;
				}
				else
				{
					if (d1 < mi)
					{
						mi = d1;
						cnt = 2;
					}
					else if (d1 == mi)
						cnt += 2;
				}
			}


		}
		cout << "#" << tc << " " << mi + abs(c1 - c2) << " " << cnt << '\n';
	}

	return 0;
}