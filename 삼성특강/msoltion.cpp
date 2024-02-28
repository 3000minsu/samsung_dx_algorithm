#include <bits/stdc++.h>
#define maa 300001
using namespace std;

struct cmp
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		if (a.first == b.first)
			return a.second < b.second;
		else
			return a.first < b.first;
	}
};

vector<multimap<int, int, cmp>> m(6);
vector<multimap<int, int, cmp>> mn(6);
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
	multimap<int, int>::iterator iter;
	if (!strcmp(mGender, "male"))
		g = 0;
	else
		g = 1;
	temp = g * 3 + (mGrade - 1);
	m[temp].insert(make_pair(mScore, mId));
	mn[temp].insert(make_pair(mId, mScore));
	iter = m[temp].end();
	iter--;
	cout << iter->second << endl;
	return iter->second;
}

int remove(int mId) {
	multimap<int, int>::iterator iter1;
	int c = 0, temp, k;
	for (int i = 0; i < 6; i++)
	{
		iter1 = mn[i].find(mId);
		if (iter1 != mn[i].end())
		{
			k = i;
			c = 1;
			break;
		}
	}
	if (c == 0)
	{
		cout << 0 << endl;
		return 0;
	}

	temp = iter1->second;
	iter1 = mn[k].erase(iter1);
	iter1 = m[k].find(temp);
	for (iter1; iter1->first != temp; iter1++)
	{
		if (iter1->second == mId)
		{
			iter1 = m[k].erase(iter1);
			break;
		}
	}
	if (m[k].empty()) {
		cout << 0 << endl;
		return 0;
	}
	else
	{
		cout << m[k].begin()->second << endl;
		return m[k].begin()->second;
	}
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore) {

	int tgender[2];
	int ch[6] = { 0 };
	multimap<int, int>::iterator iter[6];
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
			iter[i] = m[i].lower_bound(mScore);
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
		cout << 0 << endl;
		return 0;
	}
	cout << ans.second << endl;
	return ans.second;
}