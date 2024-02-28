#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, ans;
	int T, ch = 0;
	long long r, l, mid, cnt = 0;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		ans = -1;
		cin >> n;
		l = sqrt(n);
		r = 1e9 * 2;
		mid = (r + l) / 2;
		while (r >= l)
		{
			ch = 0;
			if ((mid * (mid + 1)) / 2 <= n)
			{
				l = mid + 1;
				if ((mid * (mid + 1)) / 2 == n)
					ans = mid;
			}
			else
				r = mid - 1;

			mid = (r + l) / 2;
			if (r * (r + 1) / 2 < n)
				break;
		}
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}