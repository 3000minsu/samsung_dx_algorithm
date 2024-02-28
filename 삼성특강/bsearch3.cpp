#include <bits/stdc++.h>
#define inf (1e18)*9
using namespace std;
long long candy[100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, ans, m;
	int T;
	long long r, l, mid, cnt = 0;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n>>m;
		for (int i = 0; i < n; i++)
			cin >> candy[i];

		ans = 0;
		l = 0;
		r = inf;
		mid = (r + l) / 2;
		while (r >= l&&mid>0)
		{
			cnt = 0;
			for (int i = 0; i < n; i++)
			{
				cnt += candy[i] / mid;
			}
			if(cnt>=m)
			{
				l = mid + 1;
				ans = mid;
			}
			else
				r = mid - 1;

			mid = (r + l) / 2;
		}
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}