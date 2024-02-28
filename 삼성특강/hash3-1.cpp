#include<iostream>
#include <cstring>
#define mod 100003
using namespace std;
char ori[2000][2000];
char com[2000][2000];
int ori_hash[2000] = { 0 };
int com_hash[2000][2000];
int a, b, c, d;
int cnt = 0;
int rcheck(int y, int x)
{
	int j = 0;
	for (int i = y; i < y + a; i++)
	{
		if (strncmp(ori[j], &com[i][x], b))
		{
			return 0;
		}
		j++;
	}
	return 1;
}
void make_ori()
{
	int power = 1;
	for (int i = 0; i < a; i++)
	{
		power = 1;
		for (int j = 0; j < b; j++)
		{
			ori_hash[i] += ori[i][b - 1 - j] * power;
			if (j < b - 1)
				power *= 2;
		}

	}
}
void make_com()
{
	int power = 1;
	for (int k = 0; k < c; k++)
	{
		power = 1;
		for (int i = 0; i <= d - b; i++)
		{
			if (i == 0)
			{
				for (int j = 0; j < b; j++)
				{
					com_hash[k][i] += com[k][b - 1 - j] * power;
					if (j < b - 1)
						power *= 2;
				}
			}
			else
			{
				com_hash[k][i] = 2 * (com_hash[k][i - 1] - com[k][i - 1] * power) + com[k][b - 1 + i];
			}
		}
	}

}
void cm()
{
	int ch = 0;
	for (int i = 0; i <= c - a; i++)
	{
		for (int j = 0; j <= d - b; j++)
		{
			if (com_hash[i][j] == ori_hash[0])
			{
				for (int k = 1; k < a; k++)
				{
					if (com_hash[i + k][j] != ori_hash[k])
					{
						ch = 1;
						break;
					}
				}
				if (ch == 0)
				{
					//if (rcheck(i, j))
					cnt++;
				}
				ch = 0;
			}
		}
	}
}

int main(int argc, char** argv)
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int test_case;
	int T;
	char temp;
	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> a >> b >> c >> d;
		cnt = 0;
		for (int i = 0; i < a; i++)
		{
			//for (int j = 0; j < b; j++)
			//{
			cin >> ori[i];
			//}
		}
		for (int i = 0; i < c; i++)
		{
			//for (int j = 0; j < d; j++)
			//{
			cin >> com[i];
			//}
		}
		make_ori();
		make_com();
		cm();
		cout << "#" << test_case << " " << cnt << "\n";
		memset(ori_hash, 0, sizeof(ori_hash));
		memset(com_hash, 0, sizeof(com_hash));
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}