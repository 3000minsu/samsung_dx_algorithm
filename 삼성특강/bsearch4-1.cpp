#include <bits/stdc++.h>
using namespace std;
long long p[100001][3];
int n;
int bs(int end)
{
	int l = 0, r = n - 1;
	int mid = (l + r) / 2, ans=r;
	while (r >= l)
	{
		if (p[mid][1] >= end)
		{
			r = mid - 1;
			ans = mid;
		}
		else
			l = mid + 1;
		mid = (l + r) / 2;
	}
	return ans;
}
int main()
{
	int T, l, op, a, b;
	long long mx = -1, s=0, ed;
	freopen("2_input.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		s = 0;
		mx = -1;
		scanf("%d", &l);
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &a, &b);
			p[i][0] = a;
			p[i][1] = b;
			s += (b - a);
			p[i][2] = s;
		}
		for (int i = 0; i < n; i++)
		{
			s = 0;
			ed = p[i][0] + l;
			op = bs(ed);
			s = p[op][2] - p[i][2] + p[i][1] - p[i][0];
			if (p[op][1] > ed) 
			{
				if(p[op][0] < ed)
					s -= (p[op][1] - ed);
				else
					s -= (p[op][1] - p[op][0]);
			}
			mx = max(mx, s);
			if (mx > l)
			{
				mx = l;
				break;
			}
		}
		printf("#%d %lld\n", tc, mx);
	}

	return 0;
}