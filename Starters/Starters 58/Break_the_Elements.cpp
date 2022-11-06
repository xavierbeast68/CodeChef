/**
 * @author xavierbeast68
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORL(i,a,b) for(int i = a; i <= b; i++)
#define FORR(i,a,b) for(int i = a; i >= b; i--)
#define print(x) (cout<<(x)<<endl)

void solve()
{
	/*--Let's Code--*/
	int n; cin >> n;
	vector <int> a;
	int even = 0, odd = 0;
	FOR(i, 0, n)
	{
		int x; cin >> x; a.push_back(x);
		if (x % 2 == 0)
		{
			even++;
		}
		else
		{
			odd++;
		}
	}
	if (odd >= even)
	{
		print(even);
	}
	else
	{
		if (odd == 0)
		{
			print("0");
		}
		else
		{
			print(even);
		}
	}
}

signed main()
{
	fastio;

	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
