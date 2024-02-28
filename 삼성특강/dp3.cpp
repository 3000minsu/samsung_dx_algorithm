#include <bits/stdc++.h>
using namespace std;
int dp[3001][101][101][2];
int ns[3001];
int ms[101];
int m, n;
int rec(int n_i, int m_i, int skip, int get) 
{
    
    if (n_i == n && m_i + skip == m) 
        return 0;
    if (dp[n_i][m_i][skip][get] != -1)
        return dp[n_i][m_i][skip][get];
    int& res = dp[n_i][m_i][skip][get];
    res = 0;
    if (get == 0) 
    {
        if (n_i < n) 
        {
            res = max(res, rec(n_i + 1, m_i, skip, 1) + ns[n_i]); 
            res = max(res, rec(n_i + 1, m_i, skip, 0)); 
        }
        if (m_i + skip < m) 
        {
            res = max(res, rec(n_i, m_i + 1, skip, 1) + ms[m_i]); 
            res = max(res, rec(n_i, m_i, skip + 1, 0)); 
        }
    }
    else 
    {  
        if (n_i < n) 
            res = max(res, rec(n_i + 1, m_i, skip, 0)); 
    
        if (m_i + skip < m) 
           res = max(res, rec(n_i, m_i, skip + 1, 0)); 
    }
    return res;
}
int main()
{
	int T, ans;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &ns[i]);
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
			scanf("%d", &ms[i]);
		sort(ms, ms+m, greater<int>());
        memset(dp, -1, sizeof dp);
		ans=rec(0, 0, 0, 0);
        printf("#%d %d\n", tc, ans);

	}

	return 0;
}