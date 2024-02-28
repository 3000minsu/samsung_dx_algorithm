#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T, n, i;
	int coin[8][2] = { 0 };
	//freopen("input.txt", "r", stdin);
	cin >> T;
	coin[0][0] = 50000;
	coin[1][0] = 10000;
	coin[2][0] = 5000;
	coin[3][0] = 1000;
	coin[4][0] = 500;
	coin[5][0] = 100;
	coin[6][0] = 50;
	coin[7][0] = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		i = 0;
		while (n>=10)
		{
			if (n / coin[i][0] > 0)
			{
				coin[i][1] = n / coin[i][0];
				n %= coin[i][0];
			}
			i++;
		}
		cout << "#" << test_case << "\n";
		for (int k = 0; k < 8; k++)
		{
			cout << coin[k][1] << " ";
			coin[k][1] = 0;
		}
		cout << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}