#include <bits/stdc++.h>
#include <array>
using namespace std;
array<array<set<int, greater<int>>, 5>, 5> arr;
void init()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            arr[i][j].clear();
    }

}

void hire(int mID, int mTeam, int mScore)
{
    arr[mTeam - 1][mScore - 1].insert(mID);
}

void fire(int mID)
{
    int ch = 0;
    set<int>::iterator it;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            it=arr[i][j].find(mID);
            if (it != arr[i][j].end())
            {
                it = arr[i][j].erase(it);
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
    set<int>::iterator it;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            it = arr[i][j].find(mID);
            if (it != arr[i][j].end())
            {
                it = arr[i][j].erase(it);
                ch = 1;
                temp = i;
                break;
            }
        }
        if (ch == 1)
            break;
    }
    if(ch==1)
        arr[temp][mScore - 1].insert(mID);
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
                if (!arr[mTeam - 1][i].empty())
                    arr[mTeam-1][i + mChangeScore].insert(arr[mTeam - 1][i].begin(), arr[mTeam - 1][i].end());
                arr[mTeam - 1][i].clear();
            }
            else if (4 < i + mChangeScore)
            {
                if (!arr[mTeam - 1][i].empty())
                    arr[mTeam - 1][4].insert(arr[mTeam - 1][i].begin(), arr[mTeam - 1][i].end());
                arr[mTeam - 1][i].clear();
            }
        }
    }
    else if (mChangeScore < 0)
    {
        for (int i = 1; i <= 4; i++)
        {
            if (0 <= i + mChangeScore && 4 >= i + mChangeScore)
            {
                if (!arr[mTeam - 1][i].empty())
                    arr[mTeam - 1][i + mChangeScore].insert(arr[mTeam - 1][i].begin(), arr[mTeam - 1][i].end());
                arr[mTeam - 1][i].clear();
            }
            else if (0 > i + mChangeScore)
            {
                if (!arr[mTeam - 1][i].empty())
                    arr[mTeam - 1][0].insert(arr[mTeam - 1][i].begin(), arr[mTeam - 1][i].end());
                arr[mTeam - 1][i].clear();
            }
        }
    }
    /*array < set<int, greater<int>>, 5> t;
    for (int i = 0; i < 5; i++)
    {
        if (0 <= i + mChangeScore && 4 >= i + mChangeScore)
        {
            if(!arr[mTeam - 1][i].empty())
                t[i + mChangeScore].insert(arr[mTeam - 1][i].begin(), arr[mTeam - 1][i].end());
        }
        else if (0 > i + mChangeScore)
        {
            if (!arr[mTeam - 1][i].empty())
                t[0].insert(arr[mTeam - 1][i].begin(), arr[mTeam - 1][i].end());
        }
        else if (4 < i + mChangeScore)
        {
            if (!arr[mTeam - 1][i].empty())
                t[4].insert(arr[mTeam - 1][i].begin(), arr[mTeam - 1][i].end());
        }
    }
    for (int i = 0; i < 5; i++)
    {
        arr[mTeam - 1][i].clear();
        arr[mTeam - 1][i].insert(t[i].begin(), t[i].end());
    }*/
}

int bestSoldier(int mTeam)
{
    set<int>::iterator it;
    for (int i = 4; i >= 0; i--)
    {
        if (!arr[mTeam - 1][i].empty())
        {
            it = arr[mTeam - 1][i].begin();
            //printf("%d\n", *it);
            return *it;
        }
    }
}