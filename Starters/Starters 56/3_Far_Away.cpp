/**
 * @author xavierbeast68
 * @file 3_Far_Away.cpp
 * @date 14-09-2022
 * Even a low class warrior can surpass an elite with enough hardwork.
 */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;

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

/*------------------------------------------------------------------------------------------------------------------------------------------*/


void solve()
{
	/*--Let's Code--*/
	ll n, m, distance = 0; cin >> n >> m;
	vector <ll> a(n);
	FOR(i, 0, n)
	{
		cin >> a[i];
		distance += Max2(abs(a[i] - 1), abs(a[i] - m));
	}
	cout << distance << endl;
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
		solve();
	}

	//execTime();
	return 0;
}

/**
 * check t: uncomment for multiple test cases
 * if using CPH Judge or CppFastOlympicsCoding: no need to use IOE;
 */