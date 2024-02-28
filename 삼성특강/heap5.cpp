#include <bits/stdc++.h>
using namespace std;
int main() {
	int T, n, ans, k;
	int ns[11];
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) 
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++) 
			scanf("%d", &ns[i]);
		scanf("%d", &k);
		pq.push({ 0, k });
		while (pq.top().second) 
		{
			pair<int, int> cur = pq.top();
			pq.pop();
			pq.push({ cur.first + cur.second, 0 });
			for (int i = 0; i < n; i++) 
				pq.push({ cur.first + cur.second % ns[i], cur.second / ns[i] });

		}
		ans = pq.top().first;
		printf("#%d %d\n", tc, ans);
		pq = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>();
	}
	return 0;
}