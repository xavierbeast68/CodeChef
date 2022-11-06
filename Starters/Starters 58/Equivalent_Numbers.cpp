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

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

void solve()
{
	/*--Let's Code--*/
	int a, b; cin >> a >> b;
	if (a == b)
	{
		cout << "Yes";
	}
	else if ((a % 2 == 0 && b % 2 != 0) || (a % 2 != 0 && b % 2 == 0))
	{
		cout << "No";
	}
	else
	{
		if ((a % b == 0) || (b % a == 0))
		{
			double x = log(a); double y = log(b);
			vector <double> a1; vector <double>
			if (flag1 == 1 && flag2 == 1) cout << "Yes";
			else cout << "No";
		}
		else cout << "No";
	}
	cout << endl;
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
