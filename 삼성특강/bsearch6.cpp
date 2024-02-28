#include <bits/stdc++.h>
using namespace std;
int n, k;
int level[200005];
int dat[200005];
bool ava(int mid)
{
	int j = 0; 
	int cnt = 0;

	for (int i = 0; i <n; i++) 
	{
		if (level[i] <= mid) 
			cnt++;
		else
			cnt = 0;

		if (cnt == dat[j]) 
		{
			j++;
			cnt = 0;
			if (j==k) 
				return true;
		}
	}
	return false;
}

int main()
{
	int t, mx=-1, r, l, mid, mn= 200005, ans;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++)
	{
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &level[i]);
			if (level[i] > mx)
				mx = level[i];
			if (level[i] < mn)
				mn = level[i];
		}
		for (int i = 0; i < k; i++)
			scanf("%d", &dat[i]);
		r = mx;
		l = mn;
		mid = (r + l) / 2;
		ans = r;
		while (r >= l)
		{
			if (ava(mid))
			{
				ans = mid;
				r = mid - 1;
			}
			else
				l = mid + 1;

			mid = (r + l) / 2;
		}

		printf("#%d %d\n", tc, ans);
	}

	return 0;
}