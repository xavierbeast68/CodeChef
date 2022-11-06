#include <bits/stdc++.h>
using namespace std;
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)

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
        short N;
        cin>>N;
        short a[N];
        FOR(i,N)
        {
            cin>>a[i];
        }
        string V;
        cin>>V;
        short p=101;

        FOR(i,V.length())
        {
            char c=V[i];
            if(c=='0' && p>a[i])
            {
                p=a[i];
            }
        }

        cout<<p<<endl;
    }

    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;

    return 0;
}