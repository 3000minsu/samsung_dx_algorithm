#include <bits/stdc++.h>
using namespace std;
bool visit[100][100] = { false };
int graph[100][100];
//int field[100][100];
int mi = 101, ma = 0, n, cnt=0, ans=0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void dfs(int y, int x, int i)
{
	int tx, ty;
	visit[y][x] = true;
	for (int k = 0; k < 4; k++)
	{
		ty = y + dy[k];
		tx = x + dx[k];
		if (ty >= 0 && ty < n && tx>=0 && tx < n)
		{
			if (!visit[ty][tx] && graph[ty][tx] > i)
				dfs(ty, tx, i);
		}
	}
}
int main()
{
	int ca;
	scanf("%d", &ca);
	for (int k = 0; k < ca; k++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &graph[i][j]);
				if (graph[i][j] > ma)
					ma = graph[i][j];
				if (graph[i][j] < mi)
					mi = graph[i][j];
			}
		}
		for (int i = mi-1; i <= ma+1; i++)
		{
			for (int a = 0; a < n; a++)
			{
				for (int b = 0; b < n; b++)
				{
					if (!visit[a][b] && graph[a][b] > i)
					{
						cnt++;
						dfs(a, b, i);
					}
				}
			}
			if (cnt > ans)
				ans = cnt;
			cnt = 0;
			for (int a = 0; a < n; a++)
			{
				for (int b = 0; b < n; b++)
					visit[a][b] = false;
			}
		}
		printf("#%d %d\n", k+1, ans);
		ans = 0;
		mi = 101;
		ma = 0;
	}
	return 0;
}