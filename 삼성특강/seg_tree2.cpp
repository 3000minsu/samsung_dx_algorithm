#include <bits/stdc++.h>
using namespace std;
long long arr[100002];
long long jstree[200020] = { 0 };
long long hstree[200020] = { 0 };
long long jmake_tree(int node, int start, int end)
{
	if (start == end)
	{
		jstree[node] = arr[start*2];
		return jstree[node];
	}
	int mid = (start + end) / 2;
	long long Left_Result = jmake_tree(node * 2, start, mid);
	long long Right_Result = jmake_tree(node * 2 + 1, mid + 1, end);
	jstree[node] = Left_Result + Right_Result;
	return jstree[node];
}
long long hmake_tree(int node, int start, int end)
{
	if (start == end)
	{
		hstree[node] = arr[start*2+1];
		return hstree[node];
	}
	int mid = (start + end) / 2;
	long long Left_Result = hmake_tree(node * 2, start, mid);
	long long Right_Result = hmake_tree(node * 2 + 1, mid + 1, end);
	hstree[node] = Left_Result + Right_Result;
	return hstree[node];
}
long long jsum(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		return jstree[node];
	}
	int mid = (start + end) / 2;
	long long Left_Result=jsum(node * 2, start, mid, left, right);
	long long Right_Result = jsum(node * 2 + 1, mid + 1, end, left, right);
	return Left_Result + Right_Result;
}
long long hsum(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		return hstree[node];
	}
	int mid = (start + end) / 2;
	long long Left_Result = hsum(node * 2, start, mid, left, right);
	long long Right_Result = hsum(node * 2 + 1, mid + 1, end, left, right);
	return Left_Result + Right_Result;
}



void update_jtree(int node, int start, int end, int des, long long diff)
{
	if (des > end || start > des)
		return;
	if (end == start)
	{
		jstree[node] += diff;
		return;
	}
	jstree[node] += diff;
	int mid = (end + start) / 2;
	update_jtree(node * 2, start, mid, des, diff);
	update_jtree(node * 2 + 1, mid + 1, end, des, diff);
}
void update_htree(int node, int start, int end, int des, long long diff)
{
	if (des > end || start > des)
		return;
	if (end == start)
	{
		hstree[node] += diff;
		return;
	}
	hstree[node] += diff;
	int mid = (end + start) / 2;
	update_htree(node * 2, start, mid, des, diff);
	update_htree(node * 2 + 1, mid + 1, end, des, diff);
}
int main()
{
	int T, n, q;
	int a, b;
	long long ans, c;
	//pair<int, int> temp;
	//freopen("sample_in.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		printf("#%d ", tc);
		scanf("%d %d", &n, &q);
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &arr[i]);
		}
		jmake_tree(1, 0, ((n - 1)/2));
		hmake_tree(1, 0, (n / 2)-1);
		for (int i = 0; i < q; i++)
		{
			scanf("%d %d %lld", &a, &b, &c);
			if (a == 0)
			{
				long long diff = c - arr[b];
				if (b % 2 == 0)
					update_jtree(1, 0, ((n - 1) / 2), b/2, diff);
				else
					update_htree(1, 0, (n / 2) - 1, b/2, diff);
				arr[b] = c;
			}
			else if (a == 1)
			{
				if (b == 0 && c == 1)
				{
					printf("%lld ", arr[0]);
					continue;
				}
				if (b % 2 == 0)//Â¦¼ö ½ÃÀÛ
					ans = jsum(1, 0, ((n - 1) / 2), b/2, (c-1)/2) - hsum(1, 0, (n / 2) - 1, b / 2, (c - 2) / 2);
				else
					ans = hsum(1, 0, (n / 2) - 1, b / 2, (c - 2) / 2) - jsum(1, 0, ((n - 1) / 2), (b+1) / 2, (c - 1) / 2);
				printf("%lld ", ans);
			}
		}
		printf("\n");
		memset(hstree, 0, sizeof(hstree));
		memset(jstree, 0, sizeof(jstree));
		memset(arr, 0, sizeof(arr));
	}

	return 0;
}