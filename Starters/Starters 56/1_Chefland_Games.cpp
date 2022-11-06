/**
 * @author xavierbeast68
 * @file 1_Chefland_Games.cpp
 * @date 14-09-2022
 * Even a low class warrior can surpass an elite with enough hardwork.
 */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;
typedef long double ld;

/*--Loop Macros--*/
#define FOR(i,a,b) for (i = a; i < b; ++i)
#define FORL(i,a,b) for (i = a; i <= b; ++i)
#define FORR(i,a,b) for (i = a; i >= b; --i)
/*--Minimum-Maximum Macros--*/
#define Min2(a,b,c) (a<b?a:b)
#define Max2(a,b,c) (a>b?a:b)
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

/*------------------------------------------------------------------------------------------------------------------------------------------*/


void solve()
{
	/*--Let's Code--*/
	int a, b, c, d; cin >> a >> b >> c >> d;
	cout << ((a == 0 && a == b && a == c && a == d) ? "IN" : "OUT") << endl;
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
		//debug(t);
		solve();
	}

	//execTime();
	return 0;
}

/**
 * check t: comment cin>>t; for single test case
 * if using CPH Judge or CppFastOlympicsCoding: no need to use IOE;
 */