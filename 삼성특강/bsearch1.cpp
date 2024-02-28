#include <bits/stdc++.h>
using namespace std;
int day[200001];
int seg_day[3000005] = { 0 };
int main()
{
	int T, n, p, ch, ans;
	int r, l, mid, cnt=0;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n >> p;
		for (int i = 0; i < n; i++)
		{
			cin >> day[i];
			if (i != 0)
			{
				for (int j = day[i - 1]+1; j <= day[i]; j++)
				{
					seg_day[j] = i;
				}
			}
		}
		for (int i = day[n - 1]+1; i <= day[n - 1] + day[n - 1] - day[0] + 1+p; i++)
			seg_day[i] = n;
		l = p;
		r = day[n - 1]-day[0] + 1+p;
		mid = (r + l) / 2;
		while (r >= l)
		{
			ch = 0;
			for (int i = 0; i < n; i++)//첫번째 날 설정
			{
				cnt = mid-(seg_day[day[i] + mid] - seg_day[day[i]]);
				if (cnt <= p)
				{
					ch = 1;
					break;
				}
			}
			if (ch == 1)
			{
				l = mid + 1;
				ans = mid;
			}
			else
				r = mid - 1;
			mid = (r + l) / 2;
		}
		cout << "#" << tc << " " << ans << "\n";
		memset(seg_day, 0, sizeof seg_day);
	}

	return 0;
}