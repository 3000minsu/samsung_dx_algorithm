#include<bits/stdc++.h>
#define inf 100000000
using namespace std;
int graph[100][100];
char visit[100][100] = { 0 };
int dp[100][100];
int dx[4] = { 1, -1,0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int n;
priority_queue<pair<int, pair<int, int>>> pq;
void dij()
{
	pair<int, pair<int, int>> temp;
	int tx, ty, nowx = 0, nowy = 0;
	dp[0][0] = 0;
	visit[0][0] = 0;

	do
	{
		visit[nowy][nowx] = 1;
		for (int i = 0; i < 4; i++)
		{
			ty = nowy + dy[i];
			tx = nowx + dx[i];
			if (ty >= 0 && ty < n && tx >= 0 && tx < n && visit[ty][tx] == 0)
			{
				if (dp[ty][tx] > dp[nowy][nowx] + graph[ty][tx])
				{
					dp[ty][tx] = dp[nowy][nowx] + graph[ty][tx];
					pq.push({ -dp[ty][tx], {ty, tx} });
				}
			}
		}
		do
		{
			temp = pq.top();
			pq.pop();
		} while (visit[temp.second.first][temp.second.second] != 0);
		nowx = temp.second.second;
		nowy = temp.second.first;
		if (nowx == n - 1 && nowy == n - 1)
			break;
	} while (!pq.empty());
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	freopen("input (5).txt", "r", stdin);
	scanf("%d", &T);
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				scanf("%1d", &graph[i][j]);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				dp[i][j] = inf;
				visit[i][j] = 0;
			}
		}
		pq = priority_queue<pair<int, pair<int, int>>>();
		dij();
		cout << "#" << test_case << " "<<dp[n-1][n-1]<<"\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}