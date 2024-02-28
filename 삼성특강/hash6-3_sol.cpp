#include <bits/stdc++.h>
using namespace std;
char ori[50002];
int len;
vector<list<int>> v;
int h[50002];
int arr[50002];

int make_hash(char str[])
{
	return str[0] - 97 + (str[1] - 97) * 26 + (str[2] - 97) * 26 * 26;
}


void init(int N, char init_string[])
{
	int hash;
	v.clear();
	v.resize(17576);
	memset(h, -1, sizeof h);
	strcpy(ori, init_string);
	len = N;
	for (int i = 0; i <= N - 3; i++)
	{
		hash = make_hash(&ori[i]);
		v[hash].push_back(i);
		h[i] = hash;
	}
}

int change(char string_A[], char string_B[])
{
	list<int>::iterator it;
	list<int>::iterator i;
	int pre = -10, cnt = 0, temp, o, ch, s, a_cnt=0;
	int hash_a = make_hash(string_A);
	if (v[hash_a].empty())
		return 0;
	else
	{
		v[hash_a].sort();
		s = v[hash_a].size();
		//vector<int> vt(v[hash_a].begin(), v[hash_a].end());
		//for (set<int>::iterator i=v[hash_a].begin(); i!= v[hash_a].end();i++)
		i = v[hash_a].begin();
		for (int k=0; k<s; k++)
		{
			if (*i >= pre + 3)
			{
				strncpy(&ori[*i], string_B, 3);
				for (int j = -2; j <= 2; j++)
				{
					if (*i + j >= 0 && *i + j <= len - 3)
					{
						ch = 0;
						o = h[*i + j];
						temp = make_hash(&ori[*i + j]);//새로운 거 해시값
						if (o != temp)
						{
							h[*i + j] = temp;//해시값 넣기
							v[temp].push_back(*i + j);
							if (o != hash_a)
							{
								for (it = v[o].begin(); it != v[o].end(); it++)
								{
									if (*it == *i + j)
									{
										ch = 1;
										break;
									}
								}

								if (ch == 1)
									it = v[o].erase(it);
							}
							else
							{
								arr[a_cnt++] = *i + j;
							}
						}
					}
				}
				pre = *i;
				cnt++;
			}
			i++;
		}
	}
	for (int k = 0; k < a_cnt; k++)
	{
		ch = 0;
		for (it = v[hash_a].begin(); it != v[hash_a].end(); it++)
		{
			if (*it == arr[k])
			{
				ch = 1;
				break;
			}
		}
		if(ch)
			v[hash_a].erase(it);
	}
	return cnt;
}

void result(char ret[])
{
	strcpy(ret, ori);
}