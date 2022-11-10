//* Setter's code->

#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define sp << ' ' <<
#define nl << '\n'
 
signed main() {
	cin.tie(0)->sync_with_stdio(0);
 
	int T; cin >> T;
	while(T--) {
		int N; cin >> N;
 
		int A[N];
		for(int &i : A) cin >> i;
 
		for(int i = N; --i; )
			A[i] = (A[i] < A[i-1] ? -1 : 1) * (64 - __builtin_clzll(A[i] ^ A[i-1]));
 
		int ans = 1, _cnt[61] {}, *cnt = _cnt + 30, j = 1;
 
		for(int i = 1; i < N; --cnt[A[i++]]) {
			for(; j < N && !cnt[-A[j]]; ++cnt[A[j++]]);
 
			ans = max(ans, j - i + 1);
		}
 
		cout << ans nl;
	}
}

//* Tester's code->

/*

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>   
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;   
using namespace std;  
#define ll long long  
const ll INF_MUL=1e13;
const ll INF_ADD=1e18;    
#define pb push_back                 
#define mp make_pair          
#define nline "\n"                           
#define f first                                          
#define s second                                             
#define pll pair<ll,ll> 
#define all(x) x.begin(),x.end()     
#define vl vector<ll>           
#define vvl vector<vector<ll>>    
#define vvvl vector<vector<vector<ll>>>          
#ifndef ONLINE_JUDGE    
#define debug(x) cerr<<#x<<" "; _print(x); cerr<<nline;
#else
#define debug(x);  
#endif       
void _print(ll x){cerr<<x;}  
void _print(char x){cerr<<x;}   
void _print(string x){cerr<<x;}    
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());   
template<class T,class V> void _print(pair<T,V> p) {cerr<<"{"; _print(p.first);cerr<<","; _print(p.second);cerr<<"}";}
template<class T>void _print(vector<T> v) {cerr<<" [ "; for (T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T>void _print(set<T> v) {cerr<<" [ "; for (T i:v){_print(i); cerr<<" ";}cerr<<"]";}
template<class T>void _print(multiset<T> v) {cerr<< " [ "; for (T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T,class V>void _print(map<T, V> v) {cerr<<" [ "; for(auto i:v) {_print(i);cerr<<" ";} cerr<<"]";} 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_pset;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
const ll MOD=1e9+7;     
const ll MAX=1000100; 
void solve(){  
    ll n; cin>>n;
    vector<ll> a(n+5,0);
    ll ans=1; 
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<ll>> dp(30,vector<ll>(2,0));
    for(ll i=2;i<=n;i++){
        for(ll j=29;j>=0;j--){
            ll l=min(1LL,a[i-1]&(1<<j));
            ll r=min(1LL,a[i]&(1<<j));
            if(l==r){
                continue; 
            }
            dp[j][r]=i-1;
            break; 
        }
        ll till=0; 
        for(ll j=0;j<30;j++){
            till=max(till,min(dp[j][0],dp[j][1]));
        }
        ans=max(ans,i-till);
    }
    cout<<ans<<nline; 
    return;                          
}                                    
int main()                                                                           
{    
    ios_base::sync_with_stdio(false);                         
    cin.tie(NULL);  
    #ifndef ONLINE_JUDGE                 
    freopen("input.txt", "r", stdin);                                              
    freopen("output.txt", "w", stdout);  
    freopen("error.txt", "w", stderr);                        
    #endif                          
    ll test_cases=1;               
    cin>>test_cases;
    while(test_cases--){
        solve();
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n"; 
}

//* Editorialist's Code->
/*

#include "bits/stdc++.h"
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using ll = long long int;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		vector<int> changes;
		for (int i = 0; i+1 < n; ++i) {
			int k = a[i] ^ a[i+1];
			for (int b = 30; b >= 0; --b) {
				if (k & (1 << b)) {
					if (a[i] < a[i+1]) changes.push_back(-b-1);
					else changes.push_back(b+1);
					break;
				}
			}
		}

		int mxlen = 1, R = -1;
		multiset<int> active;
		for (int L = 0; L+1 < n; ++L) {
			while (R+2 < n and active.find(-changes[R+1]) == active.end()) {
				++R;
				active.insert(changes[R]);
			}
			mxlen = max(mxlen, R-L+2);
			active.erase(active.find(changes[L]));
		}
		cout << mxlen << '\n';
	}
}

*/