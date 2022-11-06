/**
 * @author xavierbeast68
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */

//! https://www.codechef.com/START57D/problems/EVENSPLIT
//! https://www.google.com/search?q=how+to+add+a+character+a+number+of+times+in+string+in+c%2B%2B&oq=how+to+add+a+character+a+number+of+times+in+string+in+c%2B%2B&aqs=edge..69i57j0i546l4.3568j1j1&sourceid=chrome&ie=UTF-8
//! https://stackoverflow.com/questions/166630/how-can-i-repeat-a-string-a-variable-number-of-times-in-c

#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define print(x) (cout<<(x)<<endl)

void solve()
{
	/*--Let's Code--*/
	int n; cin >> n;
	string s; cin >> s;
	if (n < 3)
	{
		cout << s << endl;
	}
	else
	{
		int n1 = count(s.begin(), s.end(), '1');
		int n2 = n - n1;
		string str = "";
		str.insert(0, n2, '0');
		str.insert(n2, n1, '1');
		cout << str << endl;
	}
}

signed main()
{
	boost;
	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}


/**
 * @author xavierbeast68
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */

/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define print(x) (cout<<(x)<<endl)

void solve()
{
	int n;cin>>n;
	string s;cin>>s;
	if(n<3)
	{
	    cout<<s<<endl;
	}
	else
	{
	    string s1="";
	    for(int i=0;i<n;i++)
	    {
	        if(s[i]=='0')
	        {
	            s1=s[i]+s1;
	        }
	        else
	        {
	            s1=s1+s[i];
	        }
	    }
	    cout<<s1<<endl;
	}
}

signed main()
{
	boost;
	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
*/



