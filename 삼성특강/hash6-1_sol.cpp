#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
//unordered_multimap<string, int> m;
char ori[50002];
int len;
vector<set<int>> v;
int h[50002];

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
		hash=make_hash(&ori[i]);
		v[hash].insert(i);
		h[i] = hash;
	}
}

int change(char string_A[], char string_B[])
{
	set<int>::iterator it;
	int pre = -10, cnt=0, temp, o;
	int hash_a = make_hash(string_A);
	if (v[hash_a].empty())
		return 0;
	else
	{
		vector<int> vt(v[hash_a].begin(), v[hash_a].end());
		//for (set<int>::iterator i=v[hash_a].begin(); i!= v[hash_a].end();i++)
		for(auto i:vt)
		{
			if (i >= pre + 3)
			{
				strncpy(&ori[i], string_B, 3);
				for (int j = -2; j <= 2; j++)
				{
					if (i + j >= 0 && i + j <= len - 3)
					{
						o = h[i + j];
						temp = make_hash(&ori[i + j]);//새로운 거 해시값
						if (o != temp)
						{
							h[i + j] = temp;//해시값 넣기
							v[temp].insert(i + j);//set에 넣기
							it = v[o].lower_bound(i + j);//기존 있는거 삭제
							if (*it == i+j)
								it = v[o].erase(it);
						}
					}
				}
				pre = i;
				cnt++;
			}
		}
	}

	return cnt;
}

void result(char ret[])
{
	strcpy(ret, ori);
	/*for (int i = 0; i < len; i++)
		ret[i] = ori[i];*/

}