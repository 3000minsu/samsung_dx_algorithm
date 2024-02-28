#include<iostream>
#include <cstring>
//#define mod 100003
using namespace std;
char ori[2000][2000];
char com[2000][2000];
int ori_hash[2000] = { 0 };
int has = 0;
int com_hash[2000][2000];
int rcom_hash[2000][2000];
int a, b, c, d;
long long cnt = 0;
/*int rcheck(int y, int x)
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
}*/
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
                power *= 5831;
        }
    }
    power = 1;
    for (int j = 0; j < a; j++)
    {
        has += ori_hash[a - 1 - j] * power;
        if (j < a - 1)
            power *= 37;
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
                        power *= 5831;
                }
            }
            else
            {
                com_hash[k][i] = 5831 * (com_hash[k][i - 1] - com[k][i - 1] * power) + com[k][b - 1 + i];
            }
        }
    }
    for (int k = 0; k <= d - b; k++)
    {
        power = 1;
        for (int i = 0; i <= c - a; i++)
        {
            if (i == 0)
            {
                for (int j = 0; j < a; j++)
                {
                    rcom_hash[i][k] += com_hash[a - 1 - j][k] * power;
                    if (j < a - 1)
                        power *= 37;
                }
            }
            else
            {
                rcom_hash[i][k] = 37 * (rcom_hash[i - 1][k] - com_hash[i - 1][k] * power) + com_hash[a - 1 + i][k];
            }
        }
    }
    /*
     for (int k = 0; k <= d - b; k++)
     {
         power = 1;
         for (int i = 0; i <= c - a; i++)
         {
             if (i == 0)
             {
                 for (int j = 0; j < a; j++)
                 {
                     rcom_hash[k][i] += com_hash[k][a - 1 - j] * power;
                     if (j < a - 1)
                         power *= 3;
                 }
             }
             else
             {
                 rcom_hash[k][i] = 3 * (rcom_hash[k][i-1] - com_hash[k][i-1] * power) + com_hash[k][a - 1 + i];
             }
         }
     }*/
}
void cm()
{
    //int ch = 0;
    for (int i = 0; i <= c - a; i++)
    {
        for (int j = 0; j <= d - b; j++)
        {
            if (rcom_hash[i][j] == has)
            {
                //if(rcheck(i, j))
                cnt++;
            }
        }
    }
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_case;
    int T;
    char temp;
    //freopen("input.txt", "r", stdin);
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> a >> b >> c >> d;

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
        memset(rcom_hash, 0, sizeof(rcom_hash));
        //memset(ori, 0, sizeof(ori));
        //memset(com, 0, sizeof(com));
        has = 0;
        cnt = 0;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}