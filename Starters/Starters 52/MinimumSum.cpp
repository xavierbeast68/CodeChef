#include <bits/stdc++.h>
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);   
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
        int N;
        cin>>N;
        long long a[N];
        FOR(i,N)
        {
            cin>>a[i];
        }
        FOR(i,N)
        {
            FORL(j,i,N-1)
            {
                if(a[i]>a[j])
                {
                    a[i]=gcd(a[i],a[j]);
                }
                if(a[i]<a[j])
                {
                    a[j]=gcd(a[i],a[j]);
                }
            }
        }
        long long sum=0;
        FOR(i,N)
        {
            sum=sum + a[i];
        }
        cout<<sum<<endl;
    }

    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;

    return 0;
}