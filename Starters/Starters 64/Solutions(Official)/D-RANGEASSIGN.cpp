//* Setter's code-

#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define sp << ' ' <<
#define nl << '\n'

signed main() 
{
	cin.tie(0)->sync_with_stdio(0);

	int T; cin >> T;
	while(T--) {
		int N; cin >> N;
		int A[N];
		for(int &i : A) cin >> i;
		bool ok = A[0] == A[N-1];
		for(int i = 1; i < N; ++i)
			if(A[i] == A[N-1] && A[i-1] == A[0]) ok = 1;
		cout << (ok ? "YES" : "NO") nl;
	}	
}

//* Tester's code-
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
    vector<ll> a(n+5);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    if(a[1]==a[n]){
        cout<<"YES\n";
        return;
    }
    for(ll i=1;i<n;i++){
        if((a[i]==a[1]) and (a[i+1]==a[n])){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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
*/