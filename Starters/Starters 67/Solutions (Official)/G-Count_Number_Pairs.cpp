//$ URL-> https://www.codechef.com/problems/CNTNOPARS
//! Pre-requisite->
/*
^ Basic algebraic manipulation, frequency arrays
*/

//* Setter's Code->

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
const ll MAX=5000500;
vector<ll> freqpos(MAX,0),freqneg(MAX,0); 
void solve(){
    ll n; cin>>n;
    vector<ll> p(n+5,0);
    ll ans=0;
    for(ll i=1;i<=n;i++){
        cin>>p[i]; 
        if(p[i]%i){
            ;
        }
        else{
            ans++; 
        }      
    }
    for(ll k=1;k<=2*n;k++){
        ll till=min(n,(2*n)/k);
        ll zero=0;
        for(ll i=1;i<=till;i++){
            ll now=p[i]-i*k;
            assert(abs(now)<MAX); 
            if(now==0){     
                ans+=zero++;   
            }   
            else if(now>0){
                ans+=freqneg[now];   
                freqpos[now]++;
            }   
            else{  
                ans+=freqpos[-now];
                freqneg[-now]++;
            }
        }
        for(ll i=1;i<=till;i++){
            ll now=p[i]-i*k;
            if(now==0){
                ;
            }
            else if(now>0){
                freqpos[now]--;
            }
            else{
                freqneg[-now]--; 
            }
        }
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

import sys
input = sys.stdin.readline
for _ in range(int(input())):
    n = int(input())
    p = list(map(int, input().split()))
    ans = 0
    freq = [0 for _ in range(4*n + 10)]
    offset = 2*n
    for k in range(1, n+1):
        lim = min(2*n // k, n) + 1
        for j in range(1, lim):
            freq[p[j-1] - k*j + offset] += 1
            ans += freq[k*j - p[j-1] + offset]
        for j in range(1, lim):
            freq[p[j-1] - k*j + offset] -= 1
    print(ans)

*/