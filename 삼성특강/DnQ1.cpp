#include <bits/stdc++.h>
using namespace std;
vector<string> str;
bool cmp(string a, string b)
{
	if (a.size() == b.size())
		return a < b;
	else
		return a.size() < b.size();
}
int main()
{
	freopen("s_input.txt", "r", stdin);
	int T, n;
	string temp;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			str.push_back(temp);
		}
		sort(str.begin(), str.begin() + n, cmp);
		str.erase(unique(str.begin(), str.begin() + n), str.end());
		cout << "#" << tc << "\n";
		for (int i = 0; i < str.size(); i++)
			cout << str[i] << "\n";
		str.clear();
	}
	return 0;
}