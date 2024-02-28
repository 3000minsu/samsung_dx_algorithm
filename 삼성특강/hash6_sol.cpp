#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
unordered_multimap<string, int> m;
char ori[50002];
int len;
vector< unordered_multimap<string, int>::iterator> v(50005);
bool cm(pair<string, int> a, pair<string, int> b)
{
	return a.second < b.second;
}


void init(int N, char init_string[])
{
	unordered_multimap<string, int>::iterator it;
	strcpy(ori, init_string);
	cout << init_string;
	len = N;
	m.clear();
	//v.clear();
	char temp[3];
	for (int i = 0; i <= N - 3; i++)
	{
		strncpy(temp, &init_string[i],3);
		it=m.insert({ temp, i });
		v[i] = it;
	}
}

int change(char string_A[], char string_B[])
{
	int pre = -4;
	int cnt = 0;
	int k = 0;
	char temp[3];
	string t = string_A;
	cout << t << "\n";
	pair<unordered_multimap<string, int>::iterator, unordered_multimap<string, int>::iterator> pair1 = m.equal_range(t);
	if (pair1.first == m.end())
	{
		cout << "#" << 0 << "\n";
		return 0;
	}
	else
	{
		vector<pair<string, int>> abc(pair1.first, pair1.second);
		sort(abc.begin(), abc.end(), cm);
		for (auto j=abc.begin(); j != abc.end(); j++)
		{
			if (j->second - pre >= 3)
			{
				k = j->second;
				strncpy(&ori[k], string_B, 3);
				for (int i = 0; i < 3; i++)
				{
					m.erase(v[i + k]);
				}
				for (int i = 0; i < 3; i++)
				{
					strncpy(temp, &ori[k + i], 3);
					v[i + k] = m.insert({ temp, i + k });
				}
				pre = k;
				cnt++;
			}
		}
	}
	cout << "#"<<cnt<<"\n";
	return cnt;
}

void result(char ret[])
{
	for (int i = 0; i < len; i++)
		ret[i] = ori[i];

}