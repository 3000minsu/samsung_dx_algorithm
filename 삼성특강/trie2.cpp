#include <bits/stdc++.h>
using namespace std;
set<string> s;
int main()
{
	int T, n, ch;
	char temp[402];
	char t[402];

	freopen("input (4).txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		ch = 0;
		printf("#%d ", tc);
		scanf("%d", &n);
		scanf("%s", temp);
		for (int i = 0; i < strlen(temp); i++)
		{
			for (int j = 1; j <= strlen(temp) - i; j++)
			{
				strncpy(t, &temp[i], j);
				t[j] = '\0';
				string tt(t);
				s.insert(tt);
			}
		}
		set<string>::iterator it = s.begin();
		for (int i = 0; i < n - 1; i++)
		{
			it++;
			if (it == s.end())
			{
				ch = 1;
				break;
			}
		}
		if (ch)
			cout << "none\n";
		else
			cout << *it << "\n";
		s.clear();
	}
	return 0;
}