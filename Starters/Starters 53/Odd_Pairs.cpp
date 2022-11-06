#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll div=n/2;
        ll rem=n%2;
        if(rem==0)
        {
            cout<<n*div<<endl;
        }
        else
        {
            cout<<(n-1)*(div+1)<<endl;
        }
    }

    //cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;

}