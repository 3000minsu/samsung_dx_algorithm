#include <bits/stdc++.h>
using namespace std;
int room[402] = { 0 };
int main(int argc, char** argv)
{
	int test_case;
	int T, n, a, b, cnt;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		cnt = -1;
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			if (a > b)
				swap(a, b);
			if (b % 2 == 1)
				b++;
			if (a % 2 == 0)
				a--;
			for (int i = a; i <= b; i++)
			{
				room[i]++;
				if (room[i] > cnt)
					cnt = room[i];
			}
		}
		memset(room, 0, sizeof(room));
		cout << "#" << test_case << " "<<cnt<<"\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}