#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> v(100001);// 자식 노드 저장
vector<vector<int>> vr(100001);//레벨이랑 루트노드 저장
queue<int> qu;
long long fi(int a, int b)
{
	long long cnt = 0;
	int na = vr[a].size(), nb = vr[b].size();
	int i = na - 1;
	//cnt += nb - na;
	while (vr[a][i] != vr[b][i])
	{
		i--;
		cnt += 2;
	}
	return cnt;
}

long long bfs()
{
	long long cnt = 0;
	int temp;
	qu.push(1);
	while (!qu.empty())
	{
		for (auto iter = v[qu.front()].begin(); iter != v[qu.front()].end(); iter++)
		{
			qu.push(*iter);
		}
		temp = qu.front();
		qu.pop();
		if (!qu.empty())
			cnt += fi(temp, qu.front());
	}
	return cnt;
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test_case;
	int T, temp;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		vr[1].push_back(1);
		for (int i = 0; i < n - 1; i++)
		{
			cin >> temp;
			v[temp].push_back(i + 2);
			vr[i + 2] = vr[temp];
			vr[i + 2].push_back(i + 2);
		}
		cout << "#" << test_case << " " << bfs() << "\n";
		for (int i = 1; i <= n; i++)
		{
			vr[i].clear();
			v[i].clear();
		}
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}