#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	priority_queue<int> q;
	int test_case;
	int T, n, a, b;
	
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
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
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}