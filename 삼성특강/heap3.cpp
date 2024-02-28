#include <bits/stdc++.h>
#define mod 20171109
using namespace std;
priority_queue<int, vector<int>, greater<int>> maq;
priority_queue<int> miq;
int main(int argc, char** argv)
{
	int test_case;
	int T, n, a, b, mid;
	long long ans=0;
	int sm, bg;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		ans = 0;
		maq = priority_queue<int, vector<int>, greater<int>>();
		miq = priority_queue<int>();
		scanf("%d %d", &n, &mid);
		for (int i = 0; i < n; i++)
		{
			sm = 0, bg=0;
			scanf("%d %d", &a, &b);
			if (a <= mid)
			{
				miq.push(a);
				sm++;
			}
			else
			{
				maq.push(a);
				bg++;
			}
			if (b <= mid)
			{
				miq.push(b);
				sm++;
			}
			else
			{
				maq.push(b);
				bg++;
			}
			if (sm > bg)
			{
				maq.push(mid);
				mid = miq.top();
				miq.pop();
			}
			else if (bg > sm)
			{
				miq.push(mid);
				mid = maq.top();
				maq.pop();
			}
			ans += mid;
			ans %= mod;
		}
	
		printf("#%d %lld\n", test_case, ans);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}