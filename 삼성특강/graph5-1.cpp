#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> tree;
int depth[100001];
int parent[100001][18];
int n;
/*void dfs(int go)
{
	for (auto i : tree[go])
	{
		if (depth[i] == -1)
		{
			parent[i][0] = go;
			depth[i] = depth[go] + 1;
			dfs(i);
		}
	}
	return;
}*/
void con()
{

	for (int i = 1; i < 18; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}
	return;
}
long long lca(int u, int v)
{
	if (depth[u] < depth[v])
		swap(u, v);
	long long diff = depth[u] - depth[v];
	long long cnt = diff;
	long long temp=0;
	for (int i = 0; diff != 0; i++)
	{
		if (diff % 2 == 1)
			u = parent[u][i];
		diff /= 2;
	}

	if (u != v)
	{
		for (int i = 17; i >= 0; i--)
		{
			if (parent[u][i] != -1 && parent[u][i] != parent[v][i])
			{
				u = parent[u][i];
				v = parent[v][i];
				temp += pow(2, i);
			}
		}
		temp++;
	}
	return cnt + temp*2;
}
long long bfs()
{
	queue<int> qu;
	long long cnt = 0;
	int temp;
	qu.push(1);
	while (!qu.empty())
	{
		for (auto iter : tree[qu.front()])
		{
			qu.push(iter);
		}
		temp = qu.front();
		qu.pop();
		if (!qu.empty())
			cnt += lca(temp, qu.front());
	}
	return cnt;
}

int main()
{
	int T, a;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &n);
		tree.resize(n + 1);
		memset(parent, -1, sizeof parent);
		memset(depth, -1, sizeof depth);
		depth[1] = 0;
		for (int i = 2; i <= n ; i++)
		{
			scanf("%d", &a);
			//tree[i].push_back(a);
			tree[a].push_back(i);
			depth[i] = depth[a] + 1;
			parent[i][0] = a;
		}
		//dfs(1);
		con();
		printf("#%d %lld\n", tc, bfs());
		for (int i = 0; i <= n; i++)
			tree[i].clear();
	}

	return 0;
}