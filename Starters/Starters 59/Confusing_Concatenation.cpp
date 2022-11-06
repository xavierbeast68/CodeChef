/**
 * @author xavierbeast68
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
/*--Loop Macros--*/
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORL(i,a,b) for(int i = a; i <= b; i++)
#define FORR(i,a,b) for(int i = a; i >= b; i--)
/*--Vector Macros--*/
#define pb push_back
#define ppb pop_back
/*--Print Macros--*/
#define print(x) (cout<<(x))
#define println(x) (cout<<(x)<<endl)

/*----------------------------------------Functions----------------------------------------*/

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll max(ll a, ll b) {return a > b ? a : b;}
ll min(ll a, ll b) {return a < b ? a : b;}
ll countDigit(ll n) {return (floor(log10(n) + 1));}

/*-----------------------------------||| Here We Go!!! |||-----------------------------------*/

void solve()
{
	/*--Let's Code--*/
	int n; cin >> n;
	vector<int>c, a, b;
	FOR(i, 0, n)
	{
		int x; cin >> x;
		c.pb(x);
	}
	a.pb(c[0]);
	FOR(i, 1, n)
	{
		if (a[a.size() - 1] > c[i])
		{
			a.pb(c[i]);
		}
		else
		{
			if (c[i] > c[i + 1])
			{
				a.pb(c[i]);
			}
			else
			{
				b.pb(c[i]);
			}
		}
	}
	if (a.size() != 0 && b.size() != 0)
	{
		println(a.size());
		FOR(i, 0, a.size())
		{
			cout << a[i] << " ";
		}
		cout << endl;
		println(b.size());
		FOR(i, 0, b.size())
		{
			cout << b[i] << " ";
		}
		cout << endl;
	}
	else
	{
		println(-1);
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
