#include <bits/stdc++.h>
#define maa 300001
using namespace std;
vector<list<pair<int, int>>> li(6);
vector<list<pair<int, int>>> ni(6);

void init() {
	for (int i = 0; i < 6; i++)
	{
		li[i].clear();
		ni[i].clear();
	}
	return;
}

int add(int mId, int mGrade, char mGender[7], int mScore) {
	int g, temp, c = 0;
	list<pair<int, int>>::iterator iter;
	if (!strcmp(mGender, "male"))
	{
		g = 0;
	}
	else
	{
		g = 1;
	}
	temp = g * 3 + (mGrade - 1);
	if (li[temp].empty())
	{
		li[temp].push_back(make_pair(mScore, mId));
		ni[temp].push_back(make_pair(mId, mScore));
	}
	else
	{
		iter = lower_bound(li[temp].begin(), li[temp].end(), make_pair(mScore, mId));
		if (iter == li[temp].end())
			li[temp].push_back(make_pair(mScore, mId));
		else
			li[temp].insert(iter, make_pair(mScore, mId));
		iter = lower_bound(ni[temp].begin(), ni[temp].end(), make_pair(mId, mScore));
		if (iter == ni[temp].end())
			ni[temp].push_back(make_pair(mId, mScore));
		else
			ni[temp].insert(iter, make_pair(mId, mScore));
	}
	return li[temp].back().second;
}

int remove(int mId) {
	list<pair<int, int>>::iterator it1;
	list<pair<int, int>>::iterator it2;
	int c = 0, temp, k;
	for (int i = 0; i < 6; i++)
	{
		it1 = lower_bound(ni[i].begin(), ni[i].end(), make_pair(mId, 0));
		it2 = upper_bound(ni[i].begin(), ni[i].end(), make_pair(mId, maa));
		if (it1 != it2)
		{
			c = 1;
			k = i;
			break;
		}
	}
	if (c == 0)
		return 0;
	temp = it1->second;
	//cout << it1->first<<endl;
	it1 = ni[k].erase(it1);
	it1 = lower_bound(li[k].begin(), li[k].end(), make_pair(temp, mId));
	it1 = li[k].erase(it1);
	if (li[k].empty())
	{
		return 0;
		//cout << 0 << endl;
	}
	else
	{
		//cout << li[k].front().second << endl;
		return li[k].front().second;
	}
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore) {

	int tgender[2];
	int ch[6] = { 0 };
	list<pair<int, int>>::iterator iter[6];
	pair<int, int> ans;
	int c = 0, cnt = 0;
	
	for (int i = 0; i < mGenderCnt; i++)
	{
		if (!strcmp(mGender[i], "male"))
			tgender[i] = 0;
		else
			tgender[i] = 1;
	}
	for (int i = 0; i < mGradeCnt; i++)
	{
		for (int j = 0; j < mGenderCnt; j++)
		{
			ch[tgender[j] * 3 + (mGrade[i] - 1)] = 1;
		}
	}
	ans.first = maa;
	ans.second = 1000000001;
	for (int i = 0; i < 6; i++)
	{
		if (ch[i])
		{
			iter[i] = lower_bound(li[i].begin(), li[i].end(), make_pair(mScore, 0));
			if (iter[i] != li[i].end())
			{
				if (ans.first > iter[i]->first)
				{
					ans.first = iter[i]->first;
					ans.second = iter[i]->second;
				}
				if (ans.first == iter[i]->first)
				{
					if (ans.second > iter[i]->second)
					{
						ans.first = iter[i]->first;
						ans.second = iter[i]->second;
					}
				}
				cnt++;
			}
		}
	}
	if (cnt == 0)
		return 0;
	return ans.second;
}