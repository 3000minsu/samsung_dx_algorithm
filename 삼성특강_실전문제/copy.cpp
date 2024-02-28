#include <bits/stdc++.h>
#define inf 100000001
using namespace std;
set<pair<int, int>> blank;//{빈칸의 크기, 빈칸의 위치}
map<int, int> mem;//{할당된 메모리의 시작 주소, 할당된 메모리의 크기}
//set<int, int>
//bitset<inf> table;
int siz;
void init(int N) {
	
	mem.clear();
	blank.clear();
	siz = N;
	blank.insert({ N, 0 });//초기값으로 N크기의 빈칸삽입
	return;
}

int allocate(int mSize) {
	int s, p;
	set<pair<int, int>>::iterator it;
	it = blank.lower_bound({ mSize, -1 });//mSize 이상의 크기의 빈칸 탐색 O(logn)
	if (it == blank.end())
		return -1;
	s = it->first;
	p = it->second;
	mem[p] = mSize;//할당된 주소에 할당된 크기 대입
	blank.erase(it);//원래 있던 빈칸 정보 삭제
	if (s > mSize)
		blank.insert({ s - mSize, p + mSize });//새로운 빈칸 정보 삽입

	return p;
}

int release(int mAddr) {//해제하면서 생긴 앞뒤 빈칸 합쳐주기
	int s, p, after = 0, before = 0;
	map<int, int > ::iterator it;
	it = mem.find(mAddr);
	if (it == mem.end())
		return -1;
	s = it->second;
	p = it->first;
	it = mem.erase(it);
	//뒤쪽에 있는 빈칸의 크기 계산
	if (it != mem.end())//만약 메모리 위치가 중간이었다면
		after = it->first - (mAddr + s);
	else//맨 끝이었다면
		after = siz - (mAddr + s);

	if (after > 0)//빈칸 정보 삭제
		blank.erase({ after, mAddr + s });


	//앞쪽에 있는 빈칸의 크기 계산
	if (it != mem.begin())
	{
		it--;
		before = mAddr - (it->first + it->second);
	}
	else
		before = mAddr;

	if (before > 0)//빈칸 정보 삭제
		blank.erase({ before, mAddr - before });

	//앞 뒤 빈칸크기 합친 빈칸 삽입
	blank.insert({ s + before + after, mAddr - before });

	return s;
}