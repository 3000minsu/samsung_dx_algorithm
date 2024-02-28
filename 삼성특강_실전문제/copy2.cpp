#include <bits/stdc++.h>
using namespace std;
int n, ma = 0, k, ch = 0;
char tt[8];
void dfs(int cnt)//완전 탐색 풀이
{
	if (cnt == n)
	{
		if (ma < atoi(tt))//최대값 업데이트
			ma = atoi(tt);
		if (is_sorted(tt, tt + k, greater<int>()))//만약 그 최대값이 내림차순으로 정렬되어 있다면 탐색 중지
			ch = 1;
		return;
	}
	for (int j = 0; j < k - 1; j++)
	{
		for (int y = j + 1; y < k; y++)
		{
			swap(tt[j], tt[y]);
			if (is_sorted(tt, tt + k, greater<int>()))//만약 그 최대값이 내림차순으로 정렬되어 있다면
			{
				if ((n - cnt) % 2 == 1)//남은 교체 횟수가 짝수라면 최대값 그대로 두고 탐색 중지
				{
					ma = atoi(tt);
					ch = 1;
					return;
				}
				else
				{
					swap(tt[k - 2], tt[k - 1]);//남은 교체 회수가 홀수라면 뒷자리만 교체 후 탐색중지
					ma = atoi(tt);
					ch = 1;
					return;
				}
			}
			dfs(cnt + 1);
			if (ch == 1)
				return;
			swap(tt[j], tt[y]);
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	char nu[8];
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		ma = 0;
		ch = 0;
		cin >> nu;
		cin >> n;
		k = strlen(nu);//숫자 길이
		strcpy(tt, nu);
		dfs(0);
		cout << "#" << test_case << " " << ma << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}