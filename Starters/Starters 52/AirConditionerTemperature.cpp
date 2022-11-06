#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    short t;
    cin>>t;
    while(t--)
    {
        short a,b,c;
        cin>>a>>b>>c;
        if(b>=a && b>=c)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;

    return 0;
}