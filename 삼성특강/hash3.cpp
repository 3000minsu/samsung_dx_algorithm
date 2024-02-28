#include<iostream>
#include <cstring>
//#define MOD 1e+9
using namespace std;
char ori[2000][2000];
char com[2000][2000];
long long ori_hash[2000] = { 0 };
long long has = 0;
long long com_hash[2000][2000];
long long rcom_hash[2000][2000];
int a, b, c, d;
long long cnt = 0;
const long long MOD = 1e+9;
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

long long mod(long long v)
{
    if (v >= 0)
        return v % MOD;
    else
        return ((-v / MOD + 1) * MOD + v) % MOD;
}

void make_ori()
{
    long long power = 1, hash_value=0;
    for (int i = 0; i < a; i++)
    {
        power = 1;
        hash_value = 0;
        for (int j = 0; j < b; j++)
        {
            hash_value = mod(mod(hash_value*37)+ori[i][j]);
        }
        ori_hash[i] = hash_value;
    }
    //ori_hash[i] = mod(mod(ori[i][b - 1 - j] * power;
    hash_value = 0;
    power = 1;
    for (int j = 0; j < a; j++)
    {
        //has += ori_hash[a - 1 - j] * power;
        hash_value = mod(hash_value + mod(ori_hash[a - 1 - j] * power));
        if (j < a - 1)
            power = mod(power * 5831);
    }
    has = hash_value;
}
void make_com()
{
    long long power = 1, hash_value=0;
    for (int k = 0; k < c; k++)
    {
        power = 1;
        hash_value = 0;
        for (int i = 0; i <= d - b; i++)
        {
            if (i == 0)
            {
                for (int j = 0; j < b; j++)
                {
                    hash_value= mod(mod(hash_value * 37) + com[k][i+j]);
                    //com_hash[k][i] += com[k][b - 1 - j] * power;
                    if (j < b - 1)
                        power = mod(power*37);
                }
            }
            else
            {
                hash_value = mod(mod(37 * mod(hash_value - mod(com[k][i - 1] * power))) + com[k][b - 1 + i]);
                //com_hash[k][i] = 5381 * (com_hash[k][i - 1] - com[k][i - 1] * power) + com[k][b - 1 + i];
            }
            com_hash[k][i] = hash_value;
        }
    }
    for (int k = 0; k <= d - b; k++)
    {
        power = 1;
        hash_value = 0;
        for (int i = 0; i <= c - a; i++)
        {
            if (i == 0)
            {
                for (int j = 0; j < a; j++)
                {
                    hash_value = mod(hash_value + mod(com_hash[a - 1 - j][k] * power));
                    //rcom_hash[i][k] += com_hash[a - 1 - j][k] * power;
                    if (j < a - 1)
                        power = mod(power*5831);
                }
            }
            else
            {
                hash_value = mod(mod(5831*mod((hash_value-mod(com_hash[i - 1][k]*power))))+ com_hash[a - 1 + i][k]);
                //rcom_hash[i][k] = 17 * (rcom_hash[i - 1][k] - com_hash[i - 1][k] * power) + com_hash[a - 1 + i][k];
            }
            rcom_hash[i][k] = hash_value;
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

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int test_case;
    int T;
    //char temp;
    //freopen("input.txt", "r", stdin);
    cin >> T;

    for (test_case = 1; test_case <= T; test_case++)
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