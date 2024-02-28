#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	int n, mn;
	string temp;
	int ch = 0, k = 1;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d", &n);
		while (1)
		{
			mn = n * k;
			temp = to_string(mn);
			for (auto iter = temp.begin(); iter != temp.end(); iter++)
			{
				ch = ch | (1 << (int)(*iter - '0'));
			}
			if (ch == 1023)
			{
				break;
			}
			k++;
		}
		printf("#%d %d\n", test_case, mn);
		k = 1;
		ch = 0;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}