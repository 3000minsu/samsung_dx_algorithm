#include <stdio.h>
#include <string.h>
char num[10][7] = { "0001101", "0011001", "0010011", "0111101", "0100011", "0110001", "0101111", "0111011", "0110111", "0001011" };
char temp[100];
char ans[56];
int ran[8];
int main(int argc, char** argv)
{
	int test_case;
	int T;
	int a, b, ch = 0, p, tt;


	scanf("%d", &T);
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &a, &b);
		for (int i = 0; i < a; i++)
		{
			scanf("%s", temp);
			for (int j = 0; j < b; j++)
			{
				if (temp[j] == '1')
				{
					ch = 1;
					p = j;
				}
			}
			if (ch == 1)
			{
				break;
			}
		}
		if (ch == 1)
		{
			int k = 55;
			for (int i = p; i > p - 56; i--)
			{
				ans[k] = temp[i];
				k--;
			}
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (!strncmp(&ans[i * 7], num[j], 7))
					{
						ran[i] = j;
						break;
					}
				}
			}
			tt = (ran[0] + ran[2] + ran[4] + ran[6]) * 3 + ran[1] + ran[3] + ran[5] + ran[7];
			if (tt % 10 == 0)
			{
				tt = 0;
				for (int i = 0; i < 8; i++)
					tt += ran[i];
			}
			else
				tt = 0;
			printf("#%d %d\n", test_case, tt);
		}
		ch = 0;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}