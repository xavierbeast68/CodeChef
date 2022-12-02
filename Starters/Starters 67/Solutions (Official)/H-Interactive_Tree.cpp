//$ URL-> https://www.codechef.com/problems/INTERACTREE
//! Pre-requisite->
/*
^ Binary search, DFS
*/


//* Setter's Code->

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
ll query(vector<ll> v){
    cout<<"? "<<v.size()<<" ";
    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
    ll q; cin>>q;
    return q;
}
void guess(ll x){
    cout<<"! "<<x<<endl;
}
vector<vector<pair<ll,ll>>> adj;
ll dist[MAX],updist[MAX]; 
void dfs(ll cur,ll par){
    
    dist[cur] = updist[cur] = 0;
    for(auto it:adj[cur]){
        if(it.f!=par){
            dfs(it.f,cur);
            dist[cur]=max(dist[cur],dist[it.f]+1);
        }
    }
}
void dfs2(ll cur,ll par){
    multiset<ll> track; track.insert(-1);
    for(auto it:adj[cur]){
        if(it.f!=par){
            track.insert(dist[it.f]);
        }
    }
    for(auto it:adj[cur]){
        if(it.f!=par){
            track.erase(track.find(dist[it.f])); 
            ll x=max(*(--track.end())+1,updist[cur]);
            updist[it.f]=x+1;
            dfs2(it.f,cur); 
            track.insert(dist[it.f]); 
        }
    }
}
void solve(){     
    ll n; cin>>n;
    adj.clear(); adj.resize(n+5);
    for(ll i=1;i<n;i++){
        ll u,v; cin>>u>>v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }
    dist[1]=updist[1]=0;
    dfs(1,-1);
    dfs2(1,-1);
    vector<ll> v;
    ll q=query(v);
    vector<ll> track;
    for(ll i=1;i<=n;i++){
        if(max(dist[i],updist[i])==q){
            track.push_back(i); 
        }
    }
    while(track.size()>1){
        ll len=track.size();
        ll mid=len/2; 
        vector<ll> skip(n+5,0);
        for(ll i=0;i<mid;i++){
            for(auto it:adj[track[i]]){
                skip[it.s]=1; 
            }
        }
        v.clear();
        for(ll i=1;i<n;i++){
            if(skip[i]){
                v.push_back(i);
            }
        }
        ll q=query(v);
        if(q==0){
            v.clear();
            for(ll i=0;i<mid;i++){
                v.push_back(track[i]);
            }
            track=v;
        }
        else{
            v.clear();
            for(ll i=mid;i<len;i++){
                v.push_back(track[i]);
            }
            track=v;
        }
    }
    guess(track[0]); 
    return;       
}                              
int main()                                                                            
{ 
    ios_base::sync_with_stdio(false);                           
    cin.tie(NULL);                         
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
#define maxn 1007
using namespace std;

// -------------------- Input Checker Start --------------------

long long readInt(long long l, long long r, char endd)
{
    long long x = 0;
    int cnt = 0, fi = -1;
    bool is_neg = false;
    while(true)
    {
        char g = getchar();
        if(g == '-')
        {
            assert(fi == -1);
            is_neg = true;
            continue;
        }
        if('0' <= g && g <= '9')
        {
            x *= 10;
            x += g - '0';
            if(cnt == 0)
                fi = g - '0';
            cnt++;
            assert(fi != 0 || cnt == 1);
            assert(fi != 0 || is_neg == false);
            assert(!(cnt > 19 || (cnt == 19 && fi > 1)));
        }
        else if(g == endd)
        {
            if(is_neg)
                x = -x;
            if(!(l <= x && x <= r))
            {
                cerr << "L: " << l << ", R: " << r << ", Value Found: " << x << '\n';
                assert(false);
            }
            return x;
        }
        else
        {
            assert(false);
        }
    }
}

string readString(int l, int r, char endd)
{
    string ret = "";
    int cnt = 0;
    while(true)
    {
        char g = getchar();
        assert(g != -1);
        if(g == endd)
            break;
        cnt++;
        ret += g;
    }
    assert(l <= cnt && cnt <= r);
    return ret;
}

long long readIntSp(long long l, long long r) { return readInt(l, r, ' '); }
long long readIntLn(long long l, long long r) { return readInt(l, r, '\n'); }
string readStringSp(int l, int r) { return readString(l, r, ' '); }
string readStringLn(int l, int r) { return readString(l, r, '\n'); }
void readEOF() { assert(getchar() == EOF); }

vector<int> readVectorInt(int n, long long l, long long r)
{
    vector<int> a(n);
    for(int i = 0; i < n - 1; i++)
        a[i] = readIntSp(l, r);
    a[n - 1] = readIntLn(l, r);
    return a;
}

// -------------------- Input Checker End --------------------

int dsu[maxn];

int fnd(int n) {
    return (n == dsu[n]?n:dsu[n] = fnd(dsu[n]));
}

bool unite(int a, int b) {
    a = fnd(a);
    b = fnd(b);
    if(a == b) return false;
    dsu[a] = b;
    return true;
}

vector<pair<int, int>> edges[maxn];
vector<int> ord;
vector<int> rem(maxn);
int n;

void dfs(int now, int par) {
    for(int i = 0; i < edges[now].size(); i++) {
        if(edges[now][i].first == par) continue;
        int nxt = edges[now][i].first;
        rem[nxt] = edges[now][i].second;
        dfs(nxt, now);
    }
    ord.push_back(now);
}


bool query(vector<int> nodes) {
    cout << "? " << nodes.size();
    for(int i = 0; i < nodes.size(); i++)
        cout << " " << nodes[i];
    cout << endl;
    int ret;
    ret = readIntLn(0, n);
    return (ret > 0);
}

int main() {
	int t;
	t = readIntLn(1, 1000);
	int smn = 0;
	while(t--) {
	    n = readIntLn(3, 1000);
	    ord.clear();
	    ord.push_back(0);
	    smn += n;
	    assert(smn <= 20000);
	    rem.clear();
	    for(int i = 1; i <= n; i++) edges[i].clear(), dsu[i] = i;
	    for(int i = 1; i < n; i++) {
	        int a, b;
	        a = readIntSp(1, n);
	        b = readIntLn(1, n);
	        assert(unite(a, b));
	        edges[a].push_back({b, i});
	        edges[b].push_back({a, i});
	    }
	    dfs(1, 0);
	    int lo = 1, hi = n;
	    while(lo < hi) {
	        if(hi - lo < 3) {
	            vector<int> now;
	            for(int i = 0; i < edges[ord[lo]].size(); i++)
	                now.push_back(edges[ord[lo]][i].second);
	            if(!query(now)) break;
	            now.clear();
	            for(int i = 0; i < edges[ord[hi]].size(); i++)
	                now.push_back(edges[ord[hi]][i].second);
	            if(!query(now)) {
	                lo = hi;
	                break;
	            }
	            lo++;
	            break;
	        }
	        int mid = (lo + hi)/2;
	        vector<int> now;
	        for(int i = 1; i <= mid; i++) {
	            now.push_back(rem[ord[i]]);
	        }
	        if(query(now)) lo = mid + 1;
	        else hi = mid;
	    }
	    cout << "! " << ord[lo] << endl;
	}
	return 0;
}

*/


//*Editorialist's Code->
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

	auto ask = [&] (auto ids) {
		cout << "? " << ids.size() << ' ';
		for (int x : ids) cout << x << ' ';
		cout << endl;
		int dist; cin >> dist;
		return dist;
	};
	auto ans = [&] (int x) {
		cout << "! " << x << endl;
	};

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<vector<array<int, 2>>> adj(n+1);
		for (int i = 1; i < n; ++i) {
			int u, v; cin >> u >> v;
			adj[u].push_back({v, i});
			adj[v].push_back({u, i});
		}
		vector<int> paredge(n+1), dfsorder;
		auto dfs = [&] (const auto &self, int u, int p) -> void {
			dfsorder.push_back(u);
			for (auto [v, id] : adj[u]) {
				if (v == p) continue;
				paredge[v] = id;
				self(self, v, u);
			}
		};
		dfs(dfs, 1, 0);
		int lo = 1, hi = n-1;
		while (lo < hi) {
			int mid = (lo + hi + 1)/2;
			// Isolate all vertices from mid onwards
			vector<int> ids;
			for (int i = mid; i < n; ++i) ids.push_back(paredge[dfsorder[i]]);
			if (ask(ids)) hi = mid-1;
			else lo = mid;
		}
		if (lo > 1) {
			ans(dfsorder[lo]);
			continue;
		}
		int u = dfsorder[0], v = dfsorder[1];
		if (adj[u].size() > adj[v].size()) swap(u, v);
		vector<int> ids;
		for (auto [x, id] : adj[u]) ids.push_back(id);
		if (ask(ids)) ans(v);
		else ans(u);
	}
}

*/