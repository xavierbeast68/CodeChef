#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back

int main() {
	int t;cin>>t;
	while(t--)
	{
	    ll n;cin>>n;
	    vector <ll> a;
	    for(int i=0; i<n;i++)
	    {
	        ll x;cin>>x;
	        a.PB(x);
	    }
	    sort(a.begin(),a.end());
		ll max,min;
	    if(a[0]<0)
	    {
			if(a[n-1]<0)
			{
				max=a[0]*a[0];
				min=a[n-1]*a[n-1];
			}
			else
			{
				ll x=a[0]*a[0];
	        	ll y=a[n-1]*a[n-1];
				max=x>y?x:y;
				min=a[0]*a[n-1];
			}
	    }
		else
	    {
			min=a[0]*a[0];
			max=a[n-1]*a[n-1];
		}
		cout<<min<<" "<<max<<endl;
	}
}
