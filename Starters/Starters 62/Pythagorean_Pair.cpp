/**
 * @author xavierbeast68
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */

/*
https://www.google.com/search?q=pythagorian+pair+formula&oq=pythagorian+pair+formula&aqs=edge..69i57j0i546l5.11086j0j1&sourceid=chrome&ie=UTF-8
https://byjus.com/maths/pythagorean-triples/#:~:text=Pythagorean%20triples%20are%20a2,of%20the%20right%2Dangled%20triangle.
https://www.geeksforgeeks.org/find-two-sides-right-angle-triangle/#:~:text=To%20solve%20this%20problem%20we,the%20length%20of%20the%20hypotenuse.
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
    int nn; cin >> nn;
    int n = sqrt(nn);
    double a;
    double a1 = sqrt(n * 2 - 1);    //a->odd
    double a2 = sqrt((n - 1) * 4);  //a->even
    if (a1 > 0 && (ceil(a1) == floor(a1)))
    {
        a = a1;
        double b = (pow(a, 2) - 1) / 2.0;

        if (b > 0 && (ceil(b) == floor(b)))
        {
            cout << a << " " << b << endl;
        }
        else
        {
            println(-1);
        }
    }
    else if (a2 > 0 && (ceil(a2) == floor(a2)))
    {
        a = a2;
        double b = pow(a, 2) / 4.0 - 1;
        if (b > 0 && (ceil(b) == floor(b)))
        {
            cout << a << " " << b << endl;
        }
        else
        {
            println(-1);
        }
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
