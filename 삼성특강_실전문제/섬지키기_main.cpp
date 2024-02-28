#include <algorithm>
#include <cstring>
#include <queue>
//#include <iostream>
using namespace std;
int pattern_cnt[50000] = { 0 };
int ori_map[20][20];
int temp[25][25];
bool vi[25][25] = { false };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int n;
void init(int N, int mMap[20][20])
{
	int ty, tx, sta, ne, pat;
	memset(pattern_cnt, 0, sizeof pattern_cnt);
	n = N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ori_map[i][j] = mMap[i][j];
			temp[i + 1][j + 1] = ori_map[i][j];
		}
	}
	for (int i = 0; i <= n + 1; i++)
	{
		temp[i][0] = -1;
		temp[0][i] = -1;
		temp[i][n+1] = -1;
		temp[n+1][i] = -1;
	}
	for (int i = 0; i < N; i++)//세로
	{
		for (int j = 0; j < N; j++)//가로
		{
			sta = mMap[i][j];
			pat = 4;
			pattern_cnt[pat]++;
			for (int k = 0; k < 4; k++)//상하좌우
			{
				pat = 4;
				for (int r = 1; r < 5; r++)//m크기
				{
					ty = i + r * dy[k];
					tx = j + r * dx[k];
					pat *= 10;
					if (ty >= 0 && ty < N && tx >= 0&& tx < N)
					{
						ne = mMap[ty][tx] - sta + 4;
						pat += ne;
						pattern_cnt[pat]++;
					}
				}
			}
		}
	}
}

int palindrome_check(int m, int structure[5])
{
	int i = 0, ch=1;
	while (i < m / 2)
	{
		if (structure[i] != structure[m - 1 - i])
		{
			ch = 0;
			break;
		}
		i++;
	}
	return ch;
}

int numberOfCandidate(int M, int mStructure[5])
{
	int pat=4;
	int sta = mStructure[0];
	for (int i = 1; i < M; i++)
	{
		pat *= 10;
		pat += sta - mStructure[i] + 4;
	}
	if (M != 1&&palindrome_check(M, mStructure))
	{
		//printf("%d\n", pattern_cnt[pat] / 2);
		return pattern_cnt[pat] / 2;
	}
	else
	{
		//printf("%d\n", pattern_cnt[pat]);
		return pattern_cnt[pat];
	}
		
}

int bfs_main(int level)
{
	int cnt = 0, tx, ty;
	pair<int, int> p;
	queue<pair<int,int>> q;
	memset(vi, false, sizeof vi);
	
	q.push({ 0, 0 });
	vi[0][0] = true;
	
	while (!q.empty()) {
		p = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			ty = p.first + dy[i];
			tx = p.second + dx[i];
			if (tx >= 0 && tx <= n + 1 && ty >= 0 && ty <= n + 1 && !vi[ty][tx] && temp[ty][tx] < level)
			{
				vi[ty][tx] = 1;
				q.push({ ty, tx });
			}
		}
	}

	return ((n+2)*(n+2))-cnt;
}


int maxArea(int M, int mStructure[5], int mSeaLevel)
{
	int sta, tx, ty, ch=1, ans=-1;

	for (int i = 0; i < n; i++)//세로
	{
		for (int j = 0; j < n; j++)//가로
		{
			sta = ori_map[i][j]+mStructure[0];
			for (int k = 0; k < 4; k++)//상하좌우
			{
				ch = 1;
				for (int r = 1; r < M; r++)//m크기
				{
					ty = i + r * dy[k];
					tx = j + r * dx[k];

					if (ty >= 0 && ty < n && tx >= 0 && tx < n)
					{
						if (sta != ori_map[ty][tx] + mStructure[r])
						{
							ch = 0;
							break;
						}
					}
					else
					{
						ch = 0;
						break;
					}
				}
				if (ch)
				{
					for (int r = 0; r < M; r++)//m크기
					{
						ty = i+1 + r * dy[k];
						tx = j+1 + r * dx[k];
						temp[ty][tx] = sta;
					}
					ans = max(ans, bfs_main(mSeaLevel));
					for (int r = 0; r < M; r++)//m크기
					{
						ty = i + 1 + r * dy[k];
						tx = j + 1 + r * dx[k];
						temp[ty][tx] = ori_map[ty-1][tx-1];
					}
				}
			}
		}
	}
	//printf("%d\n", ans);
	return ans;
}