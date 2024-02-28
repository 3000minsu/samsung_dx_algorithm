#include <bits/stdc++.h>
#define maa 300001
using namespace std;
vector<set<pair<int, int>>> m(6);
vector<set<pair<int, int>>> mn(6);
void init() {
	for (int i = 0; i < 6; i++)
	{
		m[i].clear();
		mn[i].clear();
	}
	return;
}

int add(int mId, int mGrade, char mGender[7], int mScore) {
	int g, temp;
	set<pair<int, int>>::iterator iter;
	if (!strcmp(mGender, "male"))
		g = 0;
	else
		g = 1;
	temp = g * 3 + (mGrade - 1);
	m[temp].emplace( mScore, mId );
	mn[temp].emplace(mId,mScore );
	iter = m[temp].end();
	iter--;
	//cout << iter->second << endl;
	return iter->second;
}

int remove(int mId) {
	set<pair<int, int>>::iterator iter1;
	set<pair<int, int>>::iterator iter2;
	int c=0, temp, k;
	for (int i = 0; i < 6; i++)
	{
		iter1 = mn[i].lower_bound(make_pair(mId, 0));
		iter2 = mn[i].upper_bound(make_pair(mId, maa));
		if (iter1 != iter2)
		{
			k = i;
			c = 1;
			break;
		}
	}
	if (c == 0)
	{
		//cout << 0 << endl;
		return 0;
	}
		
	temp = iter1->second;
	iter1 = mn[k].erase(iter1);
	iter1 = m[k].find(make_pair(temp, mId));
	iter1 = m[k].erase(iter1);
	if (m[k].empty()) {
		//cout << 0 << endl;
		return 0;
	}
	else
	{
		//cout << m[k].begin()->second << endl;
		return m[k].begin()->second;
	}
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore) {

	int tgender[2];
	int ch[6] = { 0 };
	set<pair<int, int>>::iterator iter[6];
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
			iter[i] = m[i].lower_bound(make_pair(mScore, 0));
			if (iter[i] != m[i].end())
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
	if (cnt == 0) {
		//cout << 0 << endl;
		return 0;
	}
	//cout << ans.second << endl;
	return ans.second;
}