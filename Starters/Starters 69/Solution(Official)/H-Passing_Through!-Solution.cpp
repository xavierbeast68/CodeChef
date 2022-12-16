/*
Authors: deepak_changoi, iceknight1093
Testers: iceknight1093, mexomerf
Editorialist: iceknight1093
*/

//$ URL-> https://www.codechef.com/problems/PASSTHRU
/*
> Difficulty Rating :
% 2699 

! Pre-requisites->
^ Virtual/auxiliary trees, offline path add updates
> https://codeforces.com/blog/entry/76955
> https://discuss.codechef.com/t/icl1705-editorial/14269

* Few other problems that use virtual tress  are :
> https://www.codechef.com/problems/YATP
> https://codedrills.io/problems/tree-regression
> https://codeforces.com/contest/1725/problem/E
*/

//* Setter's Code->

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
	vector<int> time, out, dep, path, ret;
	RMQ<int> rmq;

	LCA(vector<vector<int>>& C) : time(size(C)), out(size(C)), dep(size(C)), rmq((dfs(C,0,-1), ret)) {}
	void dfs(vector<vector<int>>& C, int v, int par) {
		time[v] = T++;
		for (int y : C[v]) if (y != par) {
			path.push_back(v), ret.push_back(time[v]);
			dep[y] = 1 + dep[v];
			dfs(C, y, v);
		}
		out[v] = T;
	}

	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
};

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> col(n);
		vector adj(n, vector<int>());
		vector<array<int, 2>> edges;
		map<int, vector<int>> vertices;
		for (int i = 0; i < n; ++i) {
			cin >> col[i];
			vertices[col[i]].push_back(i);
		}
		for (int i = 0; i < n-1; ++i) {
			int u, v; cin >> u >> v;
			adj[--u].push_back(--v);
			adj[v].push_back(u);
			edges.push_back({u, v});
		}
		LCA L(adj);
		vector<ll> ans(n);
		auto upd = [&] (int x, int y, int c) { // Add c to the (x, y) path, where x is an ancestor of y
			ans[y] += c;
			ans[x] -= c;
		};

		for (auto &[c, vlist] : vertices) {
			// Build virtual tree of vertices with color c, adding to appropriate paths along the way
			sort(begin(vlist), end(vlist), [&] (int u, int v) {return L.time[u] < L.time[v];});
			int k = size(vlist);
			for (int i = 0; i+1 < k; ++i) vlist.push_back(L.lca(vlist[i], vlist[i+1]));
			sort(begin(vlist), end(vlist), [&] (int u, int v) {return L.time[u] < L.time[v];});
			vlist.erase(unique(begin(vlist), end(vlist)), end(vlist));
			stack<int> st;
			for (int x : vlist) {
				while (!st.empty()) {
					int u = st.top();
					if (L.out[u] >= L.out[x] and u != x) break;
					st.pop();
				}
				if (!st.empty()) {
					int u = st.top(); // u is the parent of x in this virtual tree
					upd(u, x, c);
				}
				st.push(x);
			}
		}

		auto dfs = [&] (const auto &self, int u, int p) -> void {
			for (int v : adj[u]) {
				if (v == p) continue;
				self(self, v, u);
				ans[u] += ans[v];
			}
		};
		dfs(dfs, 0, 0);
		for (auto [u, v] : edges) {
			if (L.time[u] > L.time[v]) swap(u, v);
			cout << ans[v] << ' ';
		}
		cout << '\n';
	}
}