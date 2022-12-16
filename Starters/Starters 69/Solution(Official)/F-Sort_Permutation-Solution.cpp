/*
Authors: satyam_343
Testers: iceknight1093, mexomerf
Editorialist: iceknight1093
*/

//$ URL-> https://www.codechef.com/problems/SORTPERM
/*
> Difficulty Rating :
% 3198 
*/

//* Setter's Code->

// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast,unroll-loops")

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
const ll MOD=998244353;     
const ll MAX=500500;
void solve(){
    ll n; cin>>n;
    vector<ll> p(n+5,0);
    ll ans=0;
    for(ll i=1;i<=n;i++){
        cin>>p[i];
        ans+=max(0LL,p[i]-i);
    }
    cout<<ans<<nline;
    vector<pair<ll,ll>> track;
    for(ll i=1;i<=n;i++){
        while(p[i]!=i){
            ll cur=i;
            for(ll j=i+1;j<=n;j++){
                if(p[j]==i){  
                    swap(p[j],p[cur]);
                    ans+=j-cur;
                    track.push_back({j,cur}); 
                    break; 
                }
                if(p[j]>p[cur]){
                    cur=j; 
                }
            }
        }
    }
    cout<<track.size()<<nline;
    for(auto it:track){
        cout<<it.f<<" "<<it.s<<nline;
    }
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

//* Tester's Code->
/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 30
void st_c() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

int main() {
  st_c();
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int p[n+1];
    vector<pair<int, int>> v;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> p[i];
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
      if(p[i] == i && cnt == i - 1){
        cnt++;
      }else{
        cnt = 0;
      }
      if(p[i] < i){
        for(int j = i - 1; j > 0; j--){
          if(p[j] > j){
            swap(p[j], p[i]);
            ans += abs(i - j);
            v.push_back({i, j});
            break;
          }
        }
        i = 0;
      }
    }
    cout<<ans<<"\n";
    cout<<v.size()<<"\n";
    for(int i = 0; i < v.size(); i++){
      cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
  }
  return 0;
}
*/

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
		vector<int> p(n+1);
		ll ans = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> p[i];
			ans += abs(p[i] - i);
		}
		cout << ans/2 << '\n';

		vector<array<int, 2>> swaps;
		vector<int> dif(n+1), pos(n+1);
		while (true) {
			bool done = true;
			for (int i = 1; i <= n; ++i) {
				done &= p[i] == i;
				dif[p[i]] = p[i] - i;
				pos[p[i]] = i;
			}
			if (done) break;
			for (int i = 1; i <= n; ++i) {
				if (dif[p[i]] >= 0) continue;
				for (int j = i-1; ; --j) {
					if (dif[p[j]] > 0) {
						swaps.push_back({i, j});
						swap(p[i], p[j]);
						break;
					}
				}
				break;
			}
		}
		cout << size(swaps) << '\n';
		for (auto [x, y] : swaps) cout << x << ' ' << y << '\n';
	}
}
*/