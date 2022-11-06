#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

	int  t;
	cin>>t;
	while(t--)
	{
	    int N,M;
	    cin>>N>>M;
	    if(N<M || !(N%M==0 && (N/M)%2==0))
	    {
	        cout<<"No"<<endl;
	    }
	    else
	    {
	        cout<<"Yes"<<endl;
	    }

	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)

void solve()
{
	

	cout<<"output"<<endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}

	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;

	return 0;
}
