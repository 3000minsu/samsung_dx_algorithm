#include <bits/stdc++.h>
using namespace std;
bool seg[100000001] = { false };
int main()
{
	int T,n, ans, m, ma=-1;
	int r, l,cnt = 0, a, b, mid;
	//freopen("2_input.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d %d", &m, &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &a, &b);
			memset(&seg[a], true, b - a);
			if (ma<b)
				ma= b;
		}
		cnt = 0;
		l = 0;
		r = m;
		mid = (r + l) / 2;
		while (r >= l)
		{
			for (int i = 0; i < b; i++)
			{
				if (seg[i])
				{

				}
			}



		}








		for (int i = 0; i < m; i++)
		{
			if (seg[i])
				cnt++;
		}
		ans = cnt;
		l = 0;
		r = m;
		while (b > r)
		{
			if (seg[l++])
				cnt--;
			if (seg[r++])
				cnt++;
			if (cnt > ans)
				ans = cnt;
		}
		printf("#%d %d\n", tc, ans);
		memset(seg, false, ma+1);
		ma = -1;
	}

	return 0;
}