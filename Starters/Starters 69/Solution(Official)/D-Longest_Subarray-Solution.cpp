/*
Authors: satyam_343
Testers: iceknight1093, mexomerf
Editorialist: iceknight1093
*/

//$ URL-> https://www.codechef.com/problems/LONGESTARRAY
/*
> Difficulty Rating :
% 2267 

! Pre-requisites->
^ Prefix Sums
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
ll freq[35][MAX];
void solve(){     
    ll n; cin>>n;
    vector<ll> till(35,n+1); 
    vector<ll> a(n+5,0);
    ll total=0;
    for(ll i=0;i<30;i++){
        freq[i][0]=0;
    }
    for(ll i=1;i<=n;i++){
        ll x; cin>>x;
        a[i]=x;
        total|=x; 
        for(ll j=0;j<30;j++){  
            freq[j][i]=freq[j][i-1]+min(1LL,x&(1<<j));
            if(x&(1<<j)){
                till[j]=i; 
            } 
        }
    }
    ll ans=-1,cur=0;
    for(ll i=1;i<=n;i++){
        ll l=n+1;
        for(ll j=0;j<30;j++){
            if(!(total&(1<<j))){  
                continue;   
            }  
            if(cur&(1<<j)){  
                ;
            }   
            else{
                l=min(l,till[j]);   
            }
        }  
        ll check=l>i;
        for(ll j=0;j<30;j++){
            if(!(total&(1<<j))){
                continue; 
            }
            if(freq[j][i-1] >= freq[j][l-1]){
                check=0;
            }
        }
        if(check){
            ans=max(ans,l-i);
        }
        cur|=a[i]; 
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


//* Editorialist's Python Code->
/*
import sys
input = sys.stdin.readline
for _ in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	first, last = [-1]*31, [-1]*31
	ct = [[0 for _ in range(31)] for _ in range(n+1)]
	for i in range(n):
		for b in range(30):
			ct[i+1][b] = ct[i][b]
			if (a[i] >> b) & 1:
				last[b] = i
				ct[i+1][b] += 1
				if first[b] == -1: first[b] = i
	ans = -1
	for i in range(n):
		r = n-1
		for b in range(30):
			if first[b] < i: continue
			r = min(r, last[b]-1)
		if r < i: continue
		len = r-i+1
		for b in range(30):
			if first[b] == -1: continue
			have = ct[r+1][b] - ct[i][b]
			if have == 0: len = -1
		ans = max(ans, len)
	print(ans)
*/