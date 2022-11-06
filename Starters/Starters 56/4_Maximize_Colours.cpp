/**
 * @author xavierbeast68
 * @file 4_Maximize_Colours.cpp
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
	int x, y, z; cin >> x >> y >> z;
	int min = Min2(x, Min2(y, z));
	if (min == 0)
	{
		if ((x + y + z) == 0 && !(x || y || z))
		{
			cout << "0" << endl;
		}
		else if ((x + y + z) == x || (x + y + z) == y || (x + y + z) == z)
		{
			cout << "1" << endl;
		}
		else if ((x == 1) || y == 1 || z == 1)
		{
			cout << "2" << endl;
		}
		else if ((x + y + z) >= 4)
		{
			cout << "3" << endl;
		}
	}
	else if (min == 1)
	{
		if (x == y && y == z)
		{
			cout << "3" << endl;
		}
		else if ((x + y + z) >= 4)
		{
			cout << "3" << endl;
		}
		else if ((x + y + z) >= 5)
		{
			cout << "4" << endl;
		}
	}
	else if (min == 2)
	{
		if (x == y && y == z)
		{
			cout << "4" << endl;
		}
		else if ((x + y + z) >= 7)
		{
			cout << "5" << endl;
		}
	}
	else
	{
		cout << "6" << endl;
	}
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
 * check t: uncomment for multiple test cases
 * if using CPH Judge or CppFastOlympicsCoding: no need to use IOE;
 */