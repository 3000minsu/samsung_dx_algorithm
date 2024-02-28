#include <bits/stdc++.h>
#include <array>
#define ma 100001
using namespace std;
array<array<bitset<ma>, 5>, 5> arr;
void init()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            arr[i][j].reset();
    }
}

void hire(int mID, int mTeam, int mScore)
{
    arr[mTeam - 1][mScore - 1][ma-mID]=1;
}

void fire(int mID)
{
    int ch = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[i][j][ma-mID])
            {
                arr[i][j][ma-mID] = 0;
                ch = 1;
                break;
            }
        }
        if (ch == 1)
            break;
    }

}

void updateSoldier(int mID, int mScore)
{
    int ch = 0, temp;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[i][j][ma - mID])
            {
                arr[i][j][ma - mID] = 0;
                ch = 1;
                temp = i;
                break;
            }
        }
        if (ch == 1)
            break;
    }
    if (ch == 1)
        arr[temp][mScore - 1][ma-mID] = 1;
}

void updateTeam(int mTeam, int mChangeScore)
{
    if (mChangeScore == 0)
        return;
    else if (mChangeScore > 0)
    {
        for (int i = 3; i >= 0; i--)
        {
            if (0 <= i + mChangeScore && 4 >= i + mChangeScore)
            {
                arr[mTeam - 1][i + mChangeScore] = arr[mTeam - 1][i + mChangeScore] | arr[mTeam - 1][i];
                arr[mTeam - 1][i].reset();
            }
            else if (4 < i + mChangeScore)
            {
                arr[mTeam - 1][4] = arr[mTeam - 1][4] | arr[mTeam - 1][i];
                arr[mTeam - 1][i].reset();
            }
        }
    }
    else if (mChangeScore < 0)
    {
        for (int i = 1; i <= 4; i++)
        {
            if (0 <= i + mChangeScore && 4 >= i + mChangeScore)
            {
                arr[mTeam - 1][i + mChangeScore] = arr[mTeam - 1][i + mChangeScore] | arr[mTeam - 1][i];
                arr[mTeam - 1][i].reset();
            }
            else if (0 > i + mChangeScore)
            {
                arr[mTeam - 1][0] = arr[mTeam - 1][0] | arr[mTeam - 1][i];
                arr[mTeam - 1][i].reset();
            }
        }
    }
}

int bestSoldier(int mTeam)
{
    unsigned long long temp=0;
    bitset<ma> t;
    t.reset();
    int i = 0;
    for (int i = 4; i >= 0; i--)
    {
        if (!arr[mTeam - 1][i].none())
        {
            t |= arr[mTeam - 1][i];
            while(1)
            {
                temp = t.to_ullong();
                if (temp == 0)
                {
                    arr[mTeam - 1][i] <<= 64;
                    i++;
                    continue;
                }
                else
                {
                    for (int j = 0; j < 64; j++)
                    {
                        if (t[j])
                            return ma-(i * 64 + j);
                    }
                }
            }
        }
    }
}