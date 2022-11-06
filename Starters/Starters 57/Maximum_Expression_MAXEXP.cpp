/**
 * @author xavierbeast68
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define print(x) (cout<<(x)<<endl)

void solve()
{
	/*--Let's Code--*/
	int n; cin >> n;
	string s; cin >> s;
	int a[10] = {0};
	int b[2] = {0};
	for (int i = 0; i < n; i++)
	{

		if (s[i] == '+')
		{
			b[0]++;
		}
		else if (s[i] == '-')
		{
			b[1]++;
		}
		else
		{
			int x = (int)s[i];
			a[x - 48]++;
		}
	}
	string str = "";
	int size = b[0] + b[1];
	int p = 0;

	for (int i = 0; i < n - size; i++)
	{
		while (!(a[p]))
		{
			p = p + 1;
		}
		str = char(p + 48) + str;
		a[p]--;
		if (b[1] != 0)
		{
			str = '-' + str;
			b[1]--;
		}
		else if (b[0] != 0)
		{
			str = '+' + str;
			b[0]--;
		}
	}
	print(str);

}

signed main()
{
	boost;
	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
