/*
! Pre-requisites:
<DFS, BFS and intuition for how it operates on a tree, finding
> Lowest Common Ancestor
> https://cp-algorithms.com/graph/lca.html
*/

//* Setter's Code->
#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int> > g;
vector<int> mxd, mxd1;

void dfs1(int c, int p, int d){
    mxd[c] = d;
    mxd1[c] = d-1;
    for(auto h:g[c]){
        if(h!=p){
            dfs1(h,c,d+1);
            if(mxd[h]>mxd[c]){
                if(mxd[c] > d) mxd1[c] = mxd[c];
                mxd[c] = mxd[h];
            }
            else if(mxd[h]>mxd1[c]){
                mxd1[c] = mxd[h];
            }
        }
    }
}


int ans;

void dfs2(int c, int p, int d, int ancd){
    if(p!=-1){
        ans += max(1ll, (min(mxd[c], ancd)-d+1))*2;
    }

    for(auto h:g[c]){
        if(h!=p){
            int tancd;
            if(mxd[h]==mxd[c]) tancd = max(ancd, mxd1[c]);
            else tancd = max(ancd, mxd[c]);
            dfs2(h,c,d+1,tancd);
        }
    }
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);
    #endif

    int tc;
    cin>>tc;

    while(tc--){
        int n;
        cin>>n;

        g.assign(n, vector<int>());
        mxd.assign(n, 0);
        mxd1.assign(n, 0);
        ans = 0;
        int x,y;

        for(int i=0; i<n-1; i++){
            cin>>x>>y;
            x--, y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        dfs1(0,-1,0);
        dfs2(0,-1,0, -1);

        ans -= mxd[0];

        cout<<ans<<'\n';

    }

    return 0;
}

//* Tester's Code->
/*

//Utkarsh.25dec
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define vl vector <ll>
#define all(c) (c).begin(),(c).end()
using namespace std;
ll power(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll modInverse(ll a){return power(a,mod-2);}
const int N=500023;
bool vis[N];
vector <int> adj[N];
const int k=25;
int up[N][k];
int tin[N],tout[N];
int timer=1;
int limit[N],level[N];
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
void dfs(int curr,int par)
{
    level[curr]=level[par]+1;
    tin[curr]=timer++;
    up[curr][0]=par;
    for(int i=1;i<k;i++)
    {
        up[curr][i]=up[up[curr][i-1]][i-1];
    }
    for(auto it:adj[curr])
    {
        if(it==par)
            continue;
        dfs(it,curr);
    }
    limit[curr]=1;
    for(auto it:adj[curr])
    {
        if(it==par)
            continue;
        limit[curr]=max(limit[curr],limit[it]+1);
    }
    tout[curr]=timer++;
}
bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = k-1; i >= 0; --i) 
    {
        if(is_ancestor(up[u][i], v))
            continue;
        else
            u=up[u][i];
    }
    return up[u][0];
}
void checktree(int curr)
{
    vis[curr]=1;
    for(auto it:adj[curr])
    {
        if(vis[it])
            continue;
        checktree(it);
    }
}
int dist(int a, int b)
{
    int L=lca(a,b);
    int ans=(level[a]+level[b]-2*level[L]);
    return ans;
}
bool cmp(int a, int b)
{
    return limit[a]<limit[b];
}
void solve()
{
    int n=readInt(1,100000,'\n');
    for(int i=1;i<=n;i++)
    {
        adj[i].clear();
        vis[i]=0;
    }
    timer=0;
    if(n==1)
    {
        cout<<0<<'\n';
        return;
    }
    for(int i=1;i<n;i++)
    {
        int u=readInt(1,n,' ');
        int v=readInt(1,n,'\n');
        assert(u!=v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    checktree(1);
    for(int i=1;i<=n;i++)
    {
        assert(vis[i]==1);
        vis[i]=0;
    }
    dfs(1,1);
    for(int i=1;i<=n;i++)
        sort(all(adj[i]),cmp);
    queue <int> q;
    q.push(1);
    vis[1]=1;
    vector <int> order;
    while(!q.empty())
    {
        auto node=q.front();
        q.pop();
        order.pb(node);
        for(auto it:adj[node])
        {
            if(vis[it])
                continue;
            q.push(it);
            vis[it]=1;
        }
    }
    ll ans=0;
    for(int i=0;i<order.size()-1;i++)
        ans+=dist(order[i],order[i+1]);
    cout<<ans<<'\n';
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

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= (int)size(V); pw *= 2, ++k) {
			jmp.emplace_back(size(V) - pw * 2 + 1);
			for (int j = 0; j < (int)size(jmp[k]); ++j)
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct LCA {
	int T = 0;
	vector<int> time, path, ret, depth;
	RMQ<int> rmq;

	LCA(vector<vector<int>>& C) : time(size(C)), depth(size(C)), rmq((dfs(C,0,-1), ret)) {}
	void dfs(vector<vector<int>>& C, int v, int par) {
		time[v] = T++;
		for (int y : C[v]) if (y != par) {
			path.push_back(v), ret.push_back(time[v]);
			depth[y] = 1 + depth[v];
			dfs(C, y, v);
		}
	}

	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
	int dist(int a, int b) { 
		return depth[a] + depth[b] - 2*depth[lca(a,b)];
	}
};

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<vector<int>> g(n);
		for (int i = 0; i < n-1; ++i) {
			int u, v; cin >> u >> v;
			g[--u].push_back(--v);
			g[v].push_back(u);
		}
		vector<int> ht(n);
		auto dfs = [&] (const auto &self, int u, int p) -> void {
			for (int v : g[u]) {
				if (v == p) continue;
				self(self, v, u);
				ht[u] = max(ht[u], ht[v]);
			}
			++ht[u];
		};
		auto bfs = [&] (int src) {
			vector<int> ord;
			queue<int> q;
			q.push(src);
			while (!q.empty()) {
				int u = q.front(); q.pop();
				ord.push_back(u);
				for (int v : g[u]) {
					if (ht[v] > ht[u]) continue;
					q.push(v);
				}
			}
			return ord;
		};
		dfs(dfs, 0, 0);
		LCA L(g);
		for (auto &v : g) {
			sort(begin(v), end(v), [&] (int x, int y) {return ht[x] < ht[y];});
		}
		auto order = bfs(0);
		ll ans = 0;
		for (int i = 0; i+1 < n; ++i) ans += L.dist(order[i], order[i+1]);
		cout << ans << '\n';
	}
}

*/