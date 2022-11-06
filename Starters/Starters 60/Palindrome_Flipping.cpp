/**
 * @author xavierbeast68
 * Problem Name- Palindrome Flipping ( Codechef Starters 60)
 * Problem Link- https://www.codechef.com/submit/FLIPPAL
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
    string s; cin >> s;
    if (n % 2 == 1)
    {
        // All odd length strings can be converted to palindromes.
        println("Yes");
    }
    else
    {
        // Only if number of 1's and 0's are even then it can be converted to palindrome else not.
        int x = count(s.begin(), s.end(), '1');
        if (x % 2 == 0)
        {
            println("Yes");
        }
        else
        {
            println("No");
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
