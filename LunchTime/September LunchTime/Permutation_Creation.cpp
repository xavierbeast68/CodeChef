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
	int n; cin >> n;
	if (n < 4)
	{
		cout << "-1" << endl;
	}
	else
	{
		int i = 2;
		while (i <= n)
		{
			cout << i << " ";
			i += 2;
		}
		i = 1;
		while (i <= n)
		{
			cout << i << " ";
			i += 2;
		}
		cout << endl;
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
