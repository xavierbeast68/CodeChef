/**
 * @author xavierbeast68
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
#define print(x) (cout<<(x)<<endl)
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORL(i,a,b) for(int i = a; i <= b; i++)
#define FORR(i,a,b) for(int i = a; i >= b; i--)

void solve()
{
	/*--Let's Code--*/
	int a, b, x; cin >> a >> b >> x;
	int y = abs(a - b);
	if (y % 2 == 0)
	{
		if ((y % x) == 0 && ((y / x) % 2) == 0)
		{
			print("Yes");
		}
		else
		{
			print("No");
		}
	}
	else
	{
		print("No");
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
