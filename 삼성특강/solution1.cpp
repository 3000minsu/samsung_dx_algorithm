#include <bits/stdc++.h>
using namespace std;
list <pair<int, int>> m1;
list <pair<int, int>> m2;
list <pair<int, int>> m3;
list <pair<int, int>> f1;
list <pair<int, int>> f2;
list <pair<int, int>> f3;
list<pair<int, int>>::iterator iter;
void init() {
	m1.clear();
	m2.clear();
	m3.clear();
	f1.clear();
	f2.clear();
	f3.clear();
	return;
}

int add(int mId, int mGrade, char mGender[7], int mScore) {
	
	if (mGrade == 1 && !strcmp(mGender, "male"))
	{
		//if (m1.empty())
			m1.push_back(make_pair(mScore, mId));
		/*else
		{
			for (iter = m1.begin(); iter != m1.end(); iter++)
			{
				if (iter->first < mScore)
				{
					iter++;
					m1.insert(iter, make_pair(mScore, mId));
				}
			}
		}*/
			m1.sort();
		return m1.back().second;
	}
	else if (mGrade == 2 && !strcmp(mGender, "male"))
	{
		//if (m2.empty())
			m2.push_back(make_pair(mScore, mId));
		/*else
		{
			for (iter = m2.begin(); iter != m2.end(); iter++)
			{
				if (iter->first < mScore)
				{
					iter++;
					m2.insert(iter, make_pair(mScore, mId));
				}
			}
		}*/
			m2.sort();
		return m2.back().second;
	}
	else if (mGrade == 3 && !strcmp(mGender, "male"))
	{
		//if (m3.empty())
			m3.push_back(make_pair(mScore, mId));
		/*else
		{
			for (iter = m3.begin(); iter != m3.end(); iter++)
			{
				if (iter->first < mScore)
				{
					iter++;
					m3.insert(iter, make_pair(mScore, mId));
				}
			}
		}*/
			m3.sort();
		return m3.back().second;
	}
	else if (mGrade == 1 && !strcmp(mGender, "female"))
	{
		//if (f1.empty())
			f1.push_back(make_pair(mScore, mId));
		/*else
		{
			for (iter = f1.begin(); iter != f1.end(); iter++)
			{
				if (iter->first < mScore)
				{
					iter++;
					f1.insert(iter, make_pair(mScore, mId));
				}
			}
		}*/
			f1.sort();
		return f1.back().second;
	}
	else if (mGrade == 2 && !strcmp(mGender, "female"))
	{
		//if (f2.empty())
			f2.push_back(make_pair(mScore, mId));
		/*else
		{
			for (iter = f2.begin(); iter != f2.end(); iter++)
			{
				if (iter->first < mScore)
				{
					iter++;
					f2.insert(iter, make_pair(mScore, mId));
				}
			}
		}*/
			f2.sort();
		return f2.back().second;
	}
	else if (mGrade == 3 && !strcmp(mGender, "female"))
	{
		//if (f3.empty())
			f3.push_back(make_pair(mScore, mId));
		/*else
		{
			for (iter = f3.begin(); iter != f3.end(); iter++)
			{
				if (iter->first < mScore)
				{
					iter++;
					f3.insert(iter, make_pair(mScore, mId));
				}
			}
		}*/
			f3.sort();
		return f3.back().second;
	}
	return 0;
}

int remove(int mId) {
	list<pair<int, int>>::iterator m1iter=m1.begin();
	list<pair<int, int>>::iterator m2iter = m2.begin();
	list<pair<int, int>>::iterator m3iter = m3.begin();
	list<pair<int, int>>::iterator f1iter = f1.begin();
	list<pair<int, int>>::iterator f2iter = f2.begin();
	list<pair<int, int>>::iterator f3iter = f3.begin();
	int cnt = 0, ch=0;
	while (1)
	{
		if (m1iter != m1.end())
		{
			if (m1iter->second == mId)
			{
				m1iter=m1.erase(m1iter);
				if (m1.empty())
					return 0;
				else
					return m1.front().second;
			}
			m1iter++;
			cnt++;
		}
		if (m2iter != m2.end())
		{
			if (m2iter->second == mId)
			{
				m2iter=m2.erase(m2iter);
				if (m2.empty())
					return 0;
				else
					return m2.front().second;
			}
			m2iter++;
			cnt++;
		}
		if (m3iter != m3.end())
		{
			if (m3iter->second == mId)
			{
				m3iter=m3.erase(m3iter);
				if (m3.empty())
					return 0;
				else
					return m3.front().second;
			}
			m3iter++;
			cnt++;
		}
		if (f1iter != f1.end())
		{
			if (f1iter->second == mId)
			{
				f1iter=f1.erase(f1iter);
				if (f1.empty())
					return 0;
				else
					return f1.front().second;
			}
			f1iter++;
			cnt++;
		}
		if (f2iter != f2.end())
		{
			if (f2iter->second == mId)
			{
				f2iter=f2.erase(f2iter);
				if (f2.empty())
					return 0;
				else
					return f2.front().second;
			}
			f2iter++;
			cnt++;
		}
		if (f3iter != f3.end())
		{
			if (f3iter->second == mId)
			{
				f3iter=f3.erase(f3iter);
				if (f3.empty())
					return 0;
				else
					return f3.front().second;
			}
			f3iter++;
			cnt++;
		}
		if (cnt == 0)
			break;
		cnt = 0;
	}
	return 0;
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore) {

	list<pair<int, int>>::iterator m1iter = m1.begin();
	list<pair<int, int>>::iterator m2iter = m2.begin();
	list<pair<int, int>>::iterator m3iter = m3.begin();
	list<pair<int, int>>::iterator f1iter = f1.begin();
	list<pair<int, int>>::iterator f2iter = f2.begin();
	list<pair<int, int>>::iterator f3iter = f3.begin();
	int ch[4][2]= { 0 };
	int cnt = 0, c=0;
	pair<int, int> l[6];
	for (int i = 0; i < mGradeCnt; i++)
	{
		for (int j = 0; j < mGenderCnt; j++)
		{
			if (!strcmp(mGender[j], "male"))
				ch[mGrade[i]][0] = 1;
			else
				ch[mGrade[i]][1] = 1;
		}
	}
	while (1)
	{
		if (ch[1][0])
		{
			if (m1iter != m1.end())
			{
				if (m1iter->first >= mScore)
				{
					l[cnt].first = m1iter->first;
					l[cnt].second = m1iter->second;
					cnt++;
					ch[1][0] = 0;
				}
				else
					ch[1][0]=0;
				c++;
				m1iter++;
			}
		}
		if (ch[2][0])
		{
			if (m2iter != m2.end())
			{
				if (m2iter->first >= mScore)
				{
					l[cnt].first = m2iter->first;
					l[cnt].second = m2iter->second;
					cnt++;
					ch[2][0] = 0;
				}
				else
					ch[2][0]=0;
				c++;
				m2iter++;
			}
		}
		if (ch[3][0])
		{
			if (m3iter != m3.end())
			{
				if (m3iter->first >= mScore)
				{
					l[cnt].first = m3iter->first;
					l[cnt].second = m3iter->second;
					cnt++;
					ch[3][0] = 0;
				}
				else
					ch[3][0]=0;
				c++;
				m3iter++;
			}
		}
		if (ch[1][1])
		{
			if (f1iter != f1.end())
			{
				if (f1iter->first >= mScore)
				{
					l[cnt].first = f1iter->first;
					l[cnt].second = f1iter->second;
					cnt++;
					ch[1][1] = 0;
				}
				else
					ch[1][1]=0;
				c++;
				f1iter++;
			}
		}
		if (ch[2][1])
		{
			if (f2iter != f2.end())
			{
				if (f2iter->first >= mScore)
				{
					l[cnt].first = f2iter->first;
					l[cnt].second = f2iter->second;
					cnt++;
					ch[2][1] = 0;
				}
				else
					ch[2][1]=0;
				c++;
				f2iter++;
			}
		}
		if (ch[3][1])
		{
			if (f3iter != f3.end())
			{
				if (f3iter->first >= mScore)
				{
					l[cnt].first = f3iter->first;
					l[cnt].second = f3iter->second;
					cnt++;
					ch[3][1] = 0;
				}
				else
					ch[3][1] = 0;
				c++;
				f3iter++;
			}
		}
		if (c == 0)
			break;
		c = 0;
	}
	if(cnt==0)
		return 0;
	sort(l, l + cnt);
	return l[0].second;

}