#include <bits/stdc++.h>
#define inf 100000001
using namespace std;
set<pair<int, int>> blank;//{��ĭ�� ũ��, ��ĭ�� ��ġ}
map<int, int> mem;//{�Ҵ�� �޸��� ���� �ּ�, �Ҵ�� �޸��� ũ��}
//set<int, int>
//bitset<inf> table;
int siz;
void init(int N) {
	
	mem.clear();
	blank.clear();
	siz = N;
	blank.insert({ N, 0 });//�ʱⰪ���� Nũ���� ��ĭ����
	return;
}

int allocate(int mSize) {
	int s, p;
	set<pair<int, int>>::iterator it;
	it = blank.lower_bound({ mSize, -1 });//mSize �̻��� ũ���� ��ĭ Ž�� O(logn)
	if (it == blank.end())
		return -1;
	s = it->first;
	p = it->second;
	mem[p] = mSize;//�Ҵ�� �ּҿ� �Ҵ�� ũ�� ����
	blank.erase(it);//���� �ִ� ��ĭ ���� ����
	if (s > mSize)
		blank.insert({ s - mSize, p + mSize });//���ο� ��ĭ ���� ����

	return p;
}

int release(int mAddr) {//�����ϸ鼭 ���� �յ� ��ĭ �����ֱ�
	int s, p, after = 0, before = 0;
	map<int, int > ::iterator it;
	it = mem.find(mAddr);
	if (it == mem.end())
		return -1;
	s = it->second;
	p = it->first;
	it = mem.erase(it);
	//���ʿ� �ִ� ��ĭ�� ũ�� ���
	if (it != mem.end())//���� �޸� ��ġ�� �߰��̾��ٸ�
		after = it->first - (mAddr + s);
	else//�� ���̾��ٸ�
		after = siz - (mAddr + s);

	if (after > 0)//��ĭ ���� ����
		blank.erase({ after, mAddr + s });


	//���ʿ� �ִ� ��ĭ�� ũ�� ���
	if (it != mem.begin())
	{
		it--;
		before = mAddr - (it->first + it->second);
	}
	else
		before = mAddr;

	if (before > 0)//��ĭ ���� ����
		blank.erase({ before, mAddr - before });

	//�� �� ��ĭũ�� ��ģ ��ĭ ����
	blank.insert({ s + before + after, mAddr - before });

	return s;
}