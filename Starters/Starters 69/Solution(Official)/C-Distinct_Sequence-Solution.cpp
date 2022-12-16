/*
Authors: satyam_343
Testers: iceknight1093, mexomerf
Editorialist: iceknight1093
*/

//$ URL-> https://www.codechef.com/problems/DISTINCTSEQ
/*
> Difficulty Rating :
% 1587 
*/


//* Setter' Code->

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
const ll MAX=100100;
void solve(){     
    ll n; cin>>n;
    string s; cin>>s;
    vector<ll> track[5];
    for(ll i=0;i<2*n;i++){
        track[s[i]-'0'].push_back(i);
    } 
    if(track[0].size()>track[1].size()){
        swap(track[0],track[1]);
    } 
    if(track[0].empty()){
        cout<<"-1\n";
    }   
    else{
        while(track[0].size()<track[1].size()){
            auto it=track[1].back();
            track[1].pop_back();
            track[0].push_back(it); 
        }
        sort(all(track[0]));
        for(auto it:track[0]){
            cout<<it+1<<" ";
        }
        cout<<nline; 
    }  
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


//* Editorialist' Python Code->
/*
for _ in range(int(input())):
    n = int(input())
    s = input()
    x, y = s.count('0'), s.count('1')
    if x == 0 or x == 2*n: print(-1)
    else:
        ans = []
        for i in range(2*n):
            if s[i] == '0' and len(ans) < n: ans.append(i+1)
        for i in range(2*n):
            if s[i] == '1' and len(ans) < n: ans.append(i+1)
        print(*sorted(ans))
*/