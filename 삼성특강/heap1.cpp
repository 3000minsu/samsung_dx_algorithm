#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	priority_queue<int> q;
	int test_case;
	int T, n, a, b;
	
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		q = priority_queue<int>();
		cin >> n;
		cout << "#" << test_case << " ";
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			if (a == 1)
			{
				cin >> b;
				q.push(b);
			}
			if (a == 2)
			{
				if (q.empty())
					cout << "-1 ";
				else
				{
					cout << q.top() << " ";
					q.pop();
				}
			}
		}
		cout << "\n";
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}