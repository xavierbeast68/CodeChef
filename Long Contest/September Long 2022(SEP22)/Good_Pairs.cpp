//! https://www.tutorialkart.com/cpp/cpp-vector-size/
//! https://www.geeksforgeeks.org/sorting-a-vector-in-c/
//! https://stackoverflow.com/questions/41623824/c-sort-vectors-time-complexity
//! https://www.geeksforgeeks.org/internal-details-of-stdsort-in-c/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back

ll combinations(ll x)
{
    if(x==1)
    {
        return 1;
    }
    else
    {
        return (x+combinations(x-1));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    // int t;cin>>t;
    // while(t--)
    // {
        ll n;cin>>n;
        vector <ll> a;
        for(ll i=0;i<n;i++)
        {
            ll x;cin>>x;
            a.PB(x);
        }
        
        sort(a.begin(), a.end());
        
        a.PB(0);
        ll pairs=0;
        ll count=1;
        ll f=a[0];
        for(ll i=1; i<=a.size(); i++)
        {
            if(a[i]==f)
            {
                count++;
            }
            else if(count>1)
            {
                pairs=pairs+combinations(count-1);
                count=1;
                f=a[i];
            }
            else
            {
                f=a[i];
            }
        }
        cout<<pairs<<endl;
    // }
}