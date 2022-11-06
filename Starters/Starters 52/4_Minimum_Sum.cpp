/**
  * @author @b xavierbeast68
  * ? Problem From : Codechef Starters 52
  * @file 4_Minimum_Sum.cpp
  * @date 16-09-2022
  * AVOIDING COMPLEXITY, REDUCES BUGS.
  */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define print(a) (cout<<(a)<<endl)
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;

/*--Loop Macros--*/
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define FORL(i,a,b) for (int i = a; i <= b; ++i)
#define FORR(i,a,b) for (int i = a; i >= b; --i)
/*--Minimum-Maximum Macros--*/
#define Min2(a,b) (a<b?a:b)
#define Max2(a,b) (a>b?a:b)
/*--Vector Macros--*/
#define pb push_back
#define ppb pop_back

/*--Execution Time--*/
#define execTime() (cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl)
/*--Debug--*/
#define debug(i) (cout<<"<==Testing(#"<<i<<")==>"<<endl)
/*--InputOutputError_From/To_File*/
void IOE()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    /*freopen("error.txt", "w", stderr);*/
#endif
}

/*------------------------------||| Here We Go!!! |||------------------------------*/

int gcd (int a, int b)
{
    return b ? gcd (b, a % b) : a;
}
void solve()
{
    /*--Let's Code--*/
    ll n; cin >> n;
    vll a(n, 0);
    FOR(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    FOR(i, 1, n)
    {
        int x = gcd(a[0], a[i]);
        if (x < a[0])
        {
            a[0] = x;
        }
    }
    print(a[0]*n);
}

signed main()
{
    boost;
    //IOE();

    /*t=1: default value for single test case*/
    int t = 1;
    cin >> t;
    while (t--)
    {
        //debug();
        solve();
    }

    //execTime();
    return 0;
}

/**
* check t: comment cin>>t; for single test case
* if using CPH Judge or CppFastOlympicsCoding: no need to use IOE;
*/