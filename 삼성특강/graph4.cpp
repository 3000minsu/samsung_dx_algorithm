#include <bits/stdc++.h>
using namespace std;
int n, bomb_cnt;
int field[301][301] = { 0 };
bool visit[301][301] = { false };
bool ch[301][301] = { false };
int bomb[90000][2];
int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[8] = {1, 0, -1, 1, 0, -1, 1, -1};
void dfs(int y, int x)
{
	int tx, ty;
	visit[y][x] = true;
	ch[y][x] = true;
	for (int j = 0; j < 8; j++)
	{
		ty = y + dy[j];
		tx = x + dx[j];
		
		if (ty >= 0 && ty < n && tx >= 0 && tx < n)
		{
			ch[ty][tx] = true;
			if(visit[ty][tx] == false && field[ty][tx] == 0)
				dfs(ty, tx);
		}
	}
}

int main()
{
	int T;
	char temp;
	int ans;
	freopen("input (4).txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		bomb_cnt = 0;
		ans = 0;
		scanf("%d", &n);
		//scanf("%d", &temp);
		getchar();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%c", &temp);
				if (temp == '*')
				{
					field[i][j] = -1;
					bomb[bomb_cnt][0] = i;
					bomb[bomb_cnt][1] = j;
					bomb_cnt++;
				}
			}
		
			scanf("%c", &temp);
		}
		int tx, ty;
		for (int i = 0; i < bomb_cnt; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				ty = bomb[i][0] + dy[j];
				tx = bomb[i][1] + dx[j];
				if (ty >= 0 && ty < n && tx >= 0 && tx < n&&field[ty][tx]!=-1)
				{
					field[ty][tx]++;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (field[i][j] == 0 && visit[i][j] == false)
				{
					dfs(i, j);
					ans++;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (ch[i][j] == false&&field[i][j]!=-1)
				{
					ans++;
				}
			}
		}
		printf("#%d %d\n", tc, ans);
		memset(ch, false, sizeof ch);
		memset(visit, false, sizeof visit);
		memset(field, 0, sizeof field);
	}

	return 0;
}