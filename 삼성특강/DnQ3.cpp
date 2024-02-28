#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int sorted[100001];
long long ans=0;
void merge(int m, int mid, int n)
{
	int i = m;
	int j = mid + 1;
	int k = m;
	//vector<int> sorted(n - m + 1);
	while (i <= mid && j <= n)
	{
		if (arr[i] > arr[j])
		{
			ans += (mid - i + 1);
			sorted[k] = arr[j];
			j++;
		}
		else
		{
			sorted[k] = arr[i];
			i++;
		}
		k++;
	}
	if (mid < i) 
	{ 
		while (j <= n)            
			sorted[k++] = arr[j++]; 
	}
	else 
	{ 
		while (i <= mid)            
			sorted[k++] = arr[i++]; 
	}    
	for (int i = m, k = m; i <= n; i++) 
		arr[i] = sorted[k++]; 
}

void mergesort(int m, int n)
{
	if (m < n)
	{
		int mid = (m + n) / 2;
		mergesort(m, mid);
		mergesort(mid + 1, n);
		merge(m, mid, n);
	}
}

int main()
{
	int T, N;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		ans = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);
		mergesort(0, N - 1);
		printf("#%d %d\n", tc, ans);
		memset(arr, 0, sizeof arr);
		memset(sorted, 0, sizeof sorted);
	}
	return 0;
}