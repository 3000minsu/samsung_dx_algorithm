#include <bits/stdc++.h>
#define inf 2000000000
using namespace std;
int arr[100002];
pair<int, int> stree[400009];
pair<int, int> make_tree(int node, int start, int end)
{
	if (start == end)
	{
		stree[node].first = arr[start];
		stree[node].second = arr[start];
		return stree[node];
	}
	int mid = (start + end) / 2;
	pair<int, int> Left_Result = make_tree(node * 2, start, mid);
	pair<int, int> Right_Result = make_tree(node * 2 + 1, mid + 1, end);
	stree[node].first = Left_Result.first > Right_Result.first ? Left_Result.first : Right_Result.first;
	stree[node].second = Left_Result.second < Right_Result.second ? Left_Result.second : Right_Result.second;
	return stree[node];
}

void cmp(int node, int start, int end, int left, int right, pair<int, int>* res)
{
	if (left > end || right < start)
	{
		return;
	}
	if (left <= start && end <= right)
	{
		res->first = res->first > stree[node].first ? res->first : stree[node].first;
		res->second = res->second < stree[node].second ? res->second : stree[node].second;
		return;
	}
	int mid = (start + end) / 2;
	cmp(node * 2, start, mid, left, right, res);
	cmp(node * 2 + 1, mid + 1, end, left, right, res);
}

pair<int, int> update_tree(int node, int start, int end, int des, int ch)
{
	if (des > end || start > des)
		return stree[node];
	if (end == start)
	{
		stree[node].first = ch;
		stree[node].second = ch;
		return stree[node];
	}
	int mid = (end + start) / 2;
	pair<int, int> Left_Result = update_tree(node * 2, start, mid, des, ch);
	pair<int, int> Right_Result = update_tree(node * 2 + 1, mid + 1, end, des, ch);
	stree[node].first = Left_Result.first > Right_Result.first ? Left_Result.first : Right_Result.first;
	stree[node].second = Left_Result.second < Right_Result.second ? Left_Result.second : Right_Result.second;
	return stree[node];
}
int main()
{
	int T, n, q;
	int a, b, c;
	int ans;
	pair<int, int> temp;
	freopen("sample_in.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		printf("#%d ", tc);
		scanf("%d %d", &n, &q);
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		make_tree(1, 0, n - 1);
		for (int i = 0; i < q; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			if (a == 0)
			{
				update_tree(1, 0, n - 1, b, c);
				arr[b] = c;
			}
			else if (a == 1)
			{
				temp.first = 0;
				temp.second = inf;
				cmp(1, 0, n - 1, b, c - 1, &temp);
				ans = temp.first - temp.second;
				printf("%d ", ans);
			}

		}
		printf("\n");
		memset(stree, 0, sizeof(stree));
	}

	return 0;
}