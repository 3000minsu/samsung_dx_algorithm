#include <bits/stdc++.h>
using namespace std;
vector<list<pair<int, int>>> li(6);
bool cmp(pair<int, int> a, pair<int, int>b)
{
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}
void init() {
	for (int i = 0; i < 6; i++)
		li[i].clear();
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
		li[temp].push_back(make_pair(mScore, mId));
	else
	{
		iter = lower_bound(li[temp].begin(), li[temp].end(), make_pair(mScore, mId), cmp);
		if (iter == li[temp].end())
			li[temp].push_back(make_pair(mScore, mId));
		else
			li[temp].insert(iter, make_pair(mScore, mId));
	}

	return li[temp].back().second;
}

int remove(int mId) {
	list<pair<int, int>>::iterator iter[6];
	int c = 0;
	for (int i = 0; i < 6; i++)
	{
		iter[i] = li[i].begin();
	}
	while (1)
	{
		for (int i = 0; i < 6; i++)
		{
			if (iter[i] != li[i].end())
			{
				if (iter[i]->second == mId)
				{
					iter[i] = li[i].erase(iter[i]);
					if (li[i].empty())
						return 0;
					else
						return li[i].front().second;
				}
				iter[i]++;
				c++;
			}
		}
		if (c == 0)
			break;
		c = 0;
	}
	return 0;
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore) {

	int tgender[2];
	int ch[6] = { 0 };
	list<pair<int, int>>::iterator iter[6];
	pair<int, int> ans[6];
	int c = 0, cnt = 0;
	for (int i = 0; i < 6; i++)
	{
		iter[i] = li[i].begin();
	}
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

	for (int i = 0; i < 6; i++)
	{
		if (ch[i])
		{
			iter[i] = lower_bound(li[i].begin(), li[i].end(), make_pair(mScore, 0), cmp);
			if (iter[i] != li[i].end())
			{
				ans[cnt].first = iter[i]->first;
				ans[cnt].second = iter[i]->second;
				cnt++;
			}
		}
	}
	if (cnt == 0)
		return 0;
	sort(ans, ans + cnt);
	return ans[0].second;
}