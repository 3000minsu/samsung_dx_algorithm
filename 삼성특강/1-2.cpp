#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test_case;
	int T;
	int n, m, ch = 0;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			if (!(m & (1 << i)))
			{
				ch = 1;
				break;
			}
		}
		if (ch == 1)
			cout << "#" << test_case + 1 << "OFF" << endl;
		else
			cout << "#" << test_case + 1 << "ON" << endl;
		ch = 0;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}