//* Setter's Code->

#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ll long long
#define db double
#define el "\n"
#define ld long double
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n;i>=0;i--)
#define rep_a(i,a,n) for(int i=a;i<n;i++)
#define all(ds) ds.begin(), ds.end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef vector< long long > vi;
typedef pair<long long, long long> ii;
typedef priority_queue <ll> pq;
#define o_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 

const ll mod = 1000000007;
const ll INF = (ll)1e18;
const ll MAXN = 1000006;

ll po(ll x, ll n){ 
    ll ans=1;
    while(n>0){ if(n&1) ans=(ans*x)%mod; x=(x*x)%mod; n/=2;}
    return ans;
}


const ll MX=1000005;
ll fac[MX];

void pre(){
 fac[0]=1;
 rep_a(i,1,MX) fac[i]= (i*fac[i-1])%mod;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T=1;
    cin >> T;
    pre();
    while(T--){
        int n;
        cin>>n;

        ll ans = 0;
        ll x;
        rep(i,n){
            cin>>x;
            ans += fac[x];
            ans%=mod;
        }

        cout<<ans<<el;

    
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}

//* Editorialist's python code->
/*

mod = 10**9 + 7
fac = [1, 1]
for x in range(2, 10**6 + 10):
    fac.append(x * fac[x-1])
    fac[x] %= mod
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    for x in a:
        ans += fac[x]
    print(ans % mod)

*/