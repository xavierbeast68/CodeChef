//$ URL-> https://www.codechef.com/problems/A_S_P
//! Pre-requisite->
/*
^ Euler tour of a tree
> https://usaco.guide/gold/tree-euler?lang=cpp
*/
/*
* Fast Hashmap
> https://codeforces.com/blog/entry/60737?f0a28=1
*/



//* Setter's Code->

#define ll long long int
#include<bits/stdc++.h>
#define loop(i,a,b) for(ll i=a;i<b;++i)
#define rloop(i,a,b) for(ll i=a;i>=b;i--)
#define in(a,n) for(ll i=0;i<n;++i) cin>>a[i];
#define pb push_back
#define mk make_pair
#define all(v) v.begin(),v.end()
#define dis(v) for(auto i:v)cout<<i<<" ";cout<<endl;
#define display(arr,n) for(int i=0; i<n; i++)cout<<arr[i]<<" ";cout<<endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);srand(time(NULL));
#define l(a) a.length()
#define fr first
#define sc second
#define mod 1000000007
#define endl '\n'
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
using namespace std;
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fr); cerr << ","; _print(p.sc); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

ll add(ll x,ll y)  {ll ans = x+y; return (ans>=mod ? ans - mod : ans);}
ll sub(ll x,ll y)  {ll ans = x-y; return (ans<0 ? ans + mod : ans);}
ll mul(ll x,ll y)  {ll ans = x*y; return (ans>=mod ? ans % mod : ans);}


#define level 20
vector<map<int,int>> t;
vector<map<int,int>> old,newly_added;

void build(vector<int> &a, int v, int tl, int tr) {
    if (tl == tr) {
        map<int,int> mp;    mp[a[tl]]++;
        t[v] = mp;
    } else { 
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        for(auto i:t[2*v])  t[v][i.fr]+=i.sc;
        for(auto i:t[2*v+1])  t[v][i.fr]+=i.sc;
    }
}




int query(int v, int tl, int tr, int l, int r, int x) {
    if (l > r)
        return 0;
    if(old[v].size()){ // if it has already been updated previously.
        if(tl!=tr)  old[2*v] = old[2*v+1] = old[v];
        t[v] = old[v];
        t[v].begin()->second = tr-tl+1;
        old[v].clear();
    }
    if (l == tl && r == tr) {
        if(t[v].find(x) == t[v].end())    return 0;
        return t[v][x];
    }
    int tm = (tl + tr) / 2;
    return (query(v*2, tl, tm, l, min(r, tm), x) + query(v*2+1, tm+1, tr, max(l, tm+1), r, x));
}




void update(int v, int tl, int tr, int l,int r, int new_val) {
    if(l > r)   return;
    // here if in some previous query we updated range from 1 to 4 but now in another query if want to break that 1 to 4 than we have to update its children so for that reason I created old vector in that i will store the previous value.
    if(old[v].size()){  // if it has already been updated previously.
        if(tl!=tr)   old[2*v] = old[2*v+1] = old[v];
        t[v] = old[v];
        t[v].begin()->second = tr-tl+1;
        old[v].clear();
    }
    // if it is in the updation range then I have to remove those color from its parents as well so i store those color in newly_added vector.
    if(l == tl && r == tr){
        newly_added[v] = t[v];
        newly_added[v][new_val]-=(tr-tl+1);
        t[v].clear();
        t[v][new_val]+=(tr-tl+1);
        // for its children I am storing its current value.
        if(tl!=tr)  old[2*v] = old[2*v+1] = t[v];
    }
    else{
        int tm = (tl+tr)/2;
        update(2*v,tl,tm,l,min(r,tm),new_val);
        update(2*v+1,tm+1,tr,max(l,tm+1),r,new_val);
        // now if its children have made some changes in his vector then we are storing it in newly_added vector so from that we have to erase those color as well from the node u.
        if(tl!=tr && newly_added[2*v].size()){
            if(v!=1){
                newly_added[v] = newly_added[2*v];
            }
            set<int> zero_count;
            for(auto i:newly_added[2*v])  {
                t[v][i.fr]-=i.sc;
                if(t[v][i.fr] == 0) zero_count.insert(i.fr);
            }
            for(auto i:zero_count)  t[v].erase(i);
            newly_added[2*v].clear();
        }
        if(tl!=tr && newly_added[2*v+1].size()){
            if(v!=1){
                for(auto i:newly_added[2*v+1])  newly_added[v][i.fr]+=i.sc;
            }
            set<int> zero_count;
            for(auto i:newly_added[2*v+1])  {
                t[v][i.fr]-=i.sc;
                if(t[v][i.fr] == 0) zero_count.insert(i.fr);
            }
            for(auto i:zero_count)  t[v].erase(i);
            newly_added[2*v+1].clear();
        }
    }
}

vector<vector<int>> vec;
vector<vector<int>> parent;
vector<int> col,in,out;
vector<int> v,height;


void precomputeSparseMatrix(int n)
{
    for (int i=1; i<level; i++)
        for (int node = 1; node <= n; node++)
                parent[node][i] = parent[parent[node][i-1]][i-1];
}


int binary_lift(ll vl,ll curr_node){
    loop(i,0,level) 
        if(vl&(1ll<<i)) 
            curr_node = parent[curr_node][i];
    return curr_node;
}




void dfs(int i,int par,int &time,int h){
    // cerr<<i<<" ";
    in[i] = ++time;
    height[i] = h;
    parent[i][0] = par;
    v.push_back(col[i-1]);
    for(auto j:vec[i])  {
        if(j!=par)  
            dfs(j,i,time,h+1); 
    }
    out[i] = ++time;
    v.pb(col[i-1]);
    // cerr<<i<<" ";
}

ll cnt = 0,tot1 = 0,tot2 = 0;

void solve(){
    int n;   cin>>n;
    assert(n>=1 && n<=3e5);
    col.assign(n,0);  in(col,n);
    loop(i,0,n) assert(col[i]>=1 && col[i]<=1e9);
    tot1+=n;
    in.assign(n+1,0);
    out.assign(n+1,0);
    vec.assign(n+1,{});
    height.assign(n+1,0);
    v.clear();
    loop(i,0,n-1){
        int a,b; cin>>a>>b;
        assert(a>=1 && a<=n);
        assert(b>=1 && b<=n);
        vec[a].pb(b);
        vec[b].pb(a);
    }
    int time = 0;
    parent.assign(n+1,vector<int>(level,0));
    dfs(1,0,time,0);
    precomputeSparseMatrix(n);
    int sz = v.size();
    sz = ceil(1.00*log2(v.size()));
    sz = (1ll<<sz); sz*=2;
    t.assign(sz,{});
    old.assign(sz,{});
    newly_added.assign(sz,{});
    build(v,1,0,v.size()-1);
    int q;   cin>>q;
    int curr_root = 1;
    loop(i,0,q){
        int type;    cin>>type;
        // debug(type)
        assert(type >= 1 && type <= 3);
        if(type == 1){
            int x,col;   cin>>x>>col;
            assert(x>=1 && x<=n);
            assert(col>=1 && col<=1e9);
            if(curr_root != 1 && (in[x] <= in[curr_root] && out[x] >= out[curr_root])){
                int diff = height[curr_root]-height[x];
                int node = (diff ? binary_lift(diff-1,curr_root) : curr_root);
                if(diff == 0){
                    int l = 1,r = v.size();
                    update(1,0,v.size()-1,l-1,r-1,col);
                }
                else{
                    int l_1 = 1,r_1 = in[node]-1,l_2 = out[node]+1,r_2 = v.size();
                    update(1,0,v.size()-1,l_1-1,r_1-1,col);
                    update(1,0,v.size()-1,l_2-1,r_2-1,col);
                }
            }
            else{
                int l = in[x],r = out[x];
                update(1,0,v.size()-1,l-1,r-1,col);
            }
        }
        else if(type == 2){
            int x;   cin>>x;
            assert(x>=1 && x<=n);
            curr_root = x;
        }
        else{
            int x,u; cin>>x>>u;
            assert(x>=1 && x<=n);
            assert(u>=1 && u<=1e9);
            ll ans = 0;
            if(curr_root != 1 && (in[x]<=in[curr_root] && out[x] >= out[curr_root])){
                int diff = height[curr_root]-height[x];
                int node = (diff ? binary_lift(diff-1,curr_root) : curr_root);
                if(diff == 0){
                    int l = 1,r = v.size();
                    ans+=query(1,0,v.size()-1,l-1,r-1,u);
                }
                else{
                    int l_1 = 1,r_1 = in[node]-1,l_2 = out[node]+1,r_2 = v.size();
                    ans+=query(1,0,v.size()-1,l_1-1,r_1-1,u);
                    ans+=query(1,0,v.size()-1,l_2-1,r_2-1,u);
                }
            }
            else{
                int l = in[x],r = out[x];
                ans+=query(1,0,v.size()-1,l-1,r-1,u);
            }
            cout<<ans/2<<endl;
        }
    }
}


int main()
{
    fast
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

//* Editorialist's Code->
/*

#include "bits/stdc++.h"
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using ll = long long int;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#include <bits/extc++.h>
using namespace __gnu_pbds;
struct chash {
	const int RANDOM = (int64_t)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now().time_since_epoch().count();
	static uint64_t hash_f(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
	int operator()(int x) const { return hash_f(x)^RANDOM; }
};
using hashmap = gp_hash_table<int, int, chash>;

struct Node {
	hashmap freq;
	Node *l = 0, *r = 0, *par = 0;
	int lo, hi;
	int change = false, val = 0;
	Node(int _lo,int _hi):lo(_lo),hi(_hi){}
	int query(int L, int R, int x) {
		if (R <= lo || hi <= L) return 0;
		if (L <= lo && hi <= R) {
			return freq[x];
		}
		push();
		return l->query(L, R, x) + r->query(L, R, x);
	}
	void set(int pos, int x) {
		freq[x]++;
		if (lo+1 == hi) return;
		push();
		if (pos >= r->lo) r->set(pos, x);
		else l->set(pos, x);
	}
	void rangeset(int L, int R, int x, bool updpar = false) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			change = true;
			val = x;
			if (updpar) {
				auto cur = par;
				while (cur) {
					for (auto &[val, ct] : freq) {
						cur -> freq[val] -= ct;
						if (cur -> freq[val] == 0) (cur -> freq).erase(val);
					}
					cur -> freq[x] += hi - lo;
					cur = cur -> par;
				}
			}
			freq.clear();
			freq[x] = hi - lo;
			return;
		}
		push();
		l->rangeset(L, R, x, updpar);
		r->rangeset(L, R, x, updpar);
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
			l -> par = r -> par = this;
		}
		if (change)
			l->rangeset(lo,hi,val), r->rangeset(lo,hi,val), change = false;
	}
};

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		vector<vector<int>> g(n);
		for (int i = 0; i < n-1; ++i) {
			int u, v; cin >> u >> v;
			g[--u].push_back(--v);
			g[v].push_back(u);
		}
		int timer = 0;
		vector<int> in(n), out(n);
		vector<array<int, 18>> anc(n);
		auto dfs = [&] (const auto &self, int u, int p) -> void {
			in[u] = timer++;
			anc[u][0] = p;
			for (int i = 1; i < 18; ++i) anc[u][i] = anc[anc[u][i-1]][i-1];
			for (int v : g[u]) {
				if (v == p) continue;
				self(self, v, u);
			}
			out[u] = timer;
		};
		auto isanc = [&] (int u, int v) {return in[u] <= in[v] and out[u] >= out[v];}; // Is u an ancestor of v?
		auto getchild = [&] (int u, int v) { // Which child of v contains u?
			for (int i = 17; i >= 0; --i) if (!isanc(anc[u][i], v)) u = anc[u][i];
			return u;
		};
		dfs(dfs, 0, 0);

		Node *segtree = new Node(0, n);
		for (int i = 0; i < n; ++i) {
			segtree -> set(in[i], a[i]);
		}
		int q; cin >> q;
		int root = 0;
		while (q--) {
			int type; cin >> type;
			if (type == 1) {
				int u, col; cin >> u >> col; --u;
				if (u == root) segtree -> rangeset(0, n, col, true);
				else if (in[u] <= in[root] and out[u] >= out[root]) {
					int v = getchild(root, u);
					segtree -> rangeset(out[v], n, col, true);
					segtree -> rangeset(0, in[v], col, true);
				}
				else segtree -> rangeset(in[u], out[u], col, true);
			} else if (type == 2) {
				cin >> root; --root;
			} else {
				int u, col; cin >> u >> col; --u;
				int ans = 0;
				if (u == root) ans = segtree -> query(0, n, col);
				else if (in[u] <= in[root] and out[u] >= out[root]) {
					int v = getchild(root, u);
					ans = segtree -> query(out[v], n, col) + segtree -> query(0, in[v], col);
				}
				else ans = segtree -> query(in[u], out[u], col);
				cout << ans << '\n';
			}
		}
	}
}

*/