#include <bits/stdc++.h>
#define inf 100000001
using namespace std;
set<pair<int, int>> blank;
map<int, int> mem;
//set<int, int>
//bitset<inf> table;
int siz;
void init(int N) {
	siz = N;
	mem.clear();
	blank.clear();
	blank.insert({ N, 0 });
	return;
}

int allocate(int mSize) {
	int s, p;
	set<pair<int, int>>::iterator it;
	it = blank.lower_bound({ mSize, -1 });
	if (it == blank.end())
		return -1;
	s = it->first;
	p = it->second;
	mem[p] = mSize;
	blank.erase(it);
	if (s > mSize)
		blank.insert({ s - mSize, p + mSize });

	return p;
}

int release(int mAddr) {
	int s, p, after=0, before=0;
	map<int, int > ::iterator it;
	it=mem.find(mAddr);
	if (it == mem.end())
		return -1;
	s = it->second;
	p = it->first;
	it = mem.erase(it);

	if (it != mem.end())
		after = it->first - (mAddr + s);
	else
		after = siz - (mAddr + s);

	if (after > 0)
		blank.erase({ after, mAddr + s });
		

	if (it != mem.begin())
	{
		it--;
		before = mAddr - (it->first + it->second);
	}
	else
		before = mAddr;

	if (before > 0)
		blank.erase({ before, mAddr - before });
		
	blank.insert({ s+before+after, mAddr-before });

	return s;
}