#include <bits/stdc++.h>
using namespace std;
set<string> s;
int main()
{
	int T, n;
	char temp[402];
	char t[402];

	//freopen("input (4).txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		printf("#%d ", tc);
		scanf("%d", &n);
		scanf("%s", temp);
		if (n > strlen(temp))
		{
			printf("none\n");
			continue;
		}
		for (int i = 0; i < strlen(temp); i++)
		{
			strcpy(t, &temp[i]);
			string tt(t);
			s.insert(tt);
		}
		set<string>::iterator it = s.begin();
		for (int i = 0; i < n - 1; i++)
			it++;
		cout << *it << "\n";
		s.clear();
	}


	return 0;
}