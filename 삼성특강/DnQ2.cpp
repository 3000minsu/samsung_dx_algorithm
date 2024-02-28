#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("s_input.txt", "r", stdin);
	int T, a, b,c, temp;
	int ra, rb, cnt=0, ans;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cnt = 0;
		cin >> a>>b>>c;
		ra = a;
		rb = b;
		do
		{
			if (a <= b)
			{
				b -= a;
				a *= 2;
			}
			else
			{
				a -= b;
				b *= 2;
			}
			cnt++;
			if (cnt == c)
				break;
			if (a == 0 || b == 0)
				break;
		}while (a != ra || b != rb);
		if (c > cnt&&a!=0&&b!=0)
		{
			temp = c % cnt;
			for (int i = 0; i < temp; i++)
			{
				if (a <= b)
				{
					b -= a;
					a *= 2;
				}
				else
				{
					a -= b;
					b *= 2;
				}
			}
		}
		ans = min(a, b);
		cout << "#" << tc << " "<<ans<<"\n";

	}
	return 0;
}