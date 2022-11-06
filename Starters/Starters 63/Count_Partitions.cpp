//* Setter's code->

#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
#pragma GCC target("avx,avx2,fma")
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
void _print(int x){cerr<<x;} 
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
    vector<ll> dp(n+5,1);  
    vector<ll> pref(n+5,1);
    vector<ll> a(n+5,0);  
    vector<ll> track;
    ll till=1;
    for(ll i=1;i<=n;i++){  
        cin>>a[i]; 
        while(!track.empty()){
            auto it=track.back();
            if(a[i]>a[it]){
                track.pop_back();
            }
            else{
                break;   
            }
        }
        if(a[i]<a[i-1]){
            till=i; 
        }
        dp[i]=pref[i-1];
        if(till!=1){
            dp[i]-=pref[till-2]; 
        }
        if(!track.empty()){
            dp[i]+=dp[track.back()];
        }
        track.push_back(i);
        dp[i]%=MOD;
        dp[i]=(dp[i]+MOD)%MOD;
        pref[i]=(pref[i-1]+dp[i])%MOD;
    }
    cout<<dp[n]<<nline;
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

//* Tester's Code->
/*
//Utkarsh.25dec
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mod 998244353
#define vl vector <ll>
#define all(c) (c).begin(),(c).end()
using namespace std;
ll power(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll modInverse(ll a){return power(a,mod-2);}
const int N=500023;
bool vis[N];
vector <int> adj[N];
long long readInt(long long l,long long r,char endd){
    long long x=0;
    int cnt=0;
    int fi=-1;
    bool is_neg=false;
    while(true){
        char g=getchar();
        if(g=='-'){
            assert(fi==-1);
            is_neg=true;
            continue;
        }
        if('0'<=g && g<='9'){
            x*=10;
            x+=g-'0';
            if(cnt==0){
                fi=g-'0';
            }
            cnt++;
            assert(fi!=0 || cnt==1);
            assert(fi!=0 || is_neg==false);

            assert(!(cnt>19 || ( cnt==19 && fi>1) ));
        } else if(g==endd){
            if(is_neg){
                x= -x;
            }

            if(!(l <= x && x <= r))
            {
                cerr << l << ' ' << r << ' ' << x << '\n';
                assert(1 == 0);
            }

            return x;
        } else {
            assert(false);
        }
    }
}
string readString(int l,int r,char endd){
    string ret="";
    int cnt=0;
    while(true){
        char g=getchar();
        assert(g!=-1);
        if(g==endd){
            break;
        }
        cnt++;
        ret+=g;
    }
    assert(l<=cnt && cnt<=r);
    return ret;
}
long long readIntSp(long long l,long long r){
    return readInt(l,r,' ');
}
long long readIntLn(long long l,long long r){
    return readInt(l,r,'\n');
}
string readStringLn(int l,int r){
    return readString(l,r,'\n');
}
string readStringSp(int l,int r){
    return readString(l,r,' ');
}
void solve()
{
    int n=readInt(1,1000000,'\n');
    int A[n+2]={0};
    int vis[n+1]={0};
    for(int i=1;i<=n;i++)
    {
        if(i==n)
            A[i]=readInt(1,n,'\n');
        else
            A[i]=readInt(1,n,' ');
        assert(vis[A[i]]==0);
        vis[A[i]]=1;
    }
    int sortedtill[n+1]={0};
    sortedtill[n]=n;
    for(int i=n-1;i>=1;i--)
    {
        if(A[i]>A[i+1])
            sortedtill[i]=i;
        else
            sortedtill[i]=sortedtill[i+1];
    }
    stack <int> s;
    s.push(1);
    int NGE[n+1]={0};
    for(int i=2;i<=n;i++)
    {
        if(s.empty())
        {
            s.push(i);
            continue;
        }
        while(s.empty()==false && A[s.top()]<A[i])
        {
            NGE[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    ll dp[n+1]={0};
    dp[n]=1;
    ll anssum[n+3]={0};
    anssum[n]=1;
    for(int i=1;i<=n;i++)
        if(NGE[i]==0)
            NGE[i]=n+1;
    for(int i=n-1;i>=1;i--)
    {
        int j=sortedtill[i];
        int validtill=NGE[j];
        // Sum of dp[i+1] to dp[validtill]
        dp[i]=anssum[i+1]+(mod-anssum[validtill+1]);
        if(validtill==n+1)
            dp[i]++;
        dp[i]%=mod;
        anssum[i]=anssum[i+1]+dp[i];
        anssum[i]%=mod;
    }
    cout<<dp[1]<<'\n';
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int T=readInt(1,100000,'\n');
    while(T--)
        solve();
    assert(getchar()==-1);
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
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

const int mod = 998244353;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> p(n);
		for (int &x : p) cin >> x;
		vector<int> dp(n), suf(n+2), nxt(n, n);
		stack<int> st; st.push(n-1);
		dp[n-1] = suf[n] = 1;
		suf[n-1] = 2;
		int peak = n-1;
		for (int i = n-2; i >= 0; --i) {
			while (!st.empty()) {
				if (p[i] > p[st.top()]) st.pop();
				else break;
			}
			if (!st.empty()) nxt[i] = st.top();
			st.push(i);

			if (p[i] > p[i+1]) peak = i;
			dp[i] = (suf[i+1] - suf[nxt[peak] + 1] + mod) % mod;
			suf[i] = (suf[i+1] + dp[i]) % mod;
		}
		cout << dp[0] << '\n';
	}
}
*/