//$ URL-> https://www.codechef.com/problems/EXISTENCEOFX

//* Preparer's Code->

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
ll getv(ll x,ll bit){
    return min(1LL,x&(1LL<<bit)); 
}
void solve(){       
    ll a,b,c,x,check; cin>>a>>b>>c;   
    vector<ll> l(31,0),r(31,0);
    for(ll i=0;i<30;i++){
        ll checka=getv(a,i),checkb=getv(b,i),checkc=getv(c,i); 
        if(checka!=checkb){
            l[i]++;
            if(l[i]%2){  
                ;
            }
            else{
                l[i+1]++;
                l[i]=0;
            }  
            r[i]=l[i]; 
        }
        else if(l[i]==checkc){
            r[i]=checkc;
            if(checka){
                l[i+1]++; 
            }
        }
        else{
            r[i]=checkc^1; 
            if(checka){
                ;
            }
            else{
                l[i+1]++;
            }  
        }   
    }  
    if(l==r){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
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

//* Editorialist's Python Code->
/*

for _ in range(int(input())):
    a, b, c = map(int, input().split())
    carry = 0
    for bit in range(28):
        x, y, z = (a >> bit) & 1, (b >> bit) & 1, (c >> bit) & 1
        if x == y and y != z: carry ^= 1
    print('No' if carry else 'Yes')

*/