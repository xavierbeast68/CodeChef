//* Pre-requisite-> Binary Lifting
//! https://cp-algorithms.com/graph/lca_binary_lifting.html

//* Setter's code->

#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define sp << ' ' <<
#define nl << '\n'

const int Z = 3e5, B = 20;

// INPUT, 0-indexed
int N;
vector<int> g[Z];
// ................

int dfsTimer, tin[Z], sz[Z], t[Z], e[Z], p[Z][B], q[Z][B], l[Z][B], r[Z][B];
bool h[Z][B];

void dfs(int u) {
	e[tin[u] = dfsTimer++] = u;

	for(int i = 0; i + 1 < B; ++i) {
		p[u][i+1] = p[p[u][i]][i];
		q[u][i+1] = q[p[u][i]][i];
		h[u][i+1] = h[p[u][i]][i];
	}
	sort(begin(g[u]), end(g[u]));

	for(int v : g[u]) {
		if(v != p[u][0]) {
			p[v][0] = u;
			q[v][0] = v;
			h[v][0] = 1;
			dfs(v);
		} else
			l[u][0] = dfsTimer - tin[u];
	}
	sz[u] = dfsTimer - tin[u];

	int add {};
	for(int v : g[u]) {
		if(v != p[u][0]) t[v] = tin[v] - tin[u] + add;
		else add = N - sz[u];
	}

	r[u][0] = l[u][0] + (N - sz[u]) - 1;
}

int query(int u, int x) {
	for(int i = B; i--; ) if(h[u][i]) {
		if(l[u][i] <= x && x <= r[u][i]) {
			x -= l[u][i];
			if(t[q[u][i]] <= x) x += sz[q[u][i]];
			u = p[u][i];
		}
	}
	if(!u) return e[x];

	if(x < l[u][0])	return e[tin[u] + x];
	return e[tin[u] + x - (N - sz[u])];
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);

	int T; cin >> T;
	while(T--) {
		cin >> N;
		for(int i = 0; i < N; ++i) {
			g[i].clear();
			fill(h[i], h[i] + B, 0);
		}
		dfsTimer = 0;

		for(int i = 1; i < N; ++i) {
			int u, v; cin >> u >> v;
			--u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		dfs(0);

		for(int i = 0; i + 1 < B; ++i) {
			for(int u = 1; u < N; ++u) {
				int &lv = l[u][i+1] = l[p[u][i]][i];
				int &rv = r[u][i+1] = r[p[u][i]][i];

				if(p[u][i] && q[u][i] < p[p[u][i]][0]) {
					lv -= sz[q[u][i]];
					rv -= sz[q[u][i]];
				}

				lv += l[u][i];
				rv += l[u][i];
			}
		}

		int Q, last {}; cin >> Q;
		while(Q--) {
			int u, x; cin >> u >> x;
			cout << (last = query((u ^ last) - 1, x ^ last) + 1) nl;
		}
	}
}

//* Editorialist's code->

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

	const int LOG = 19;

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<vector<int>> adj(n+1);
		for (int i = 1; i < n; ++i) {
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (int i = 1; i <= n; ++i) sort(begin(adj[i]), end(adj[i]));

		vector<int> tin(n+1), ord, subsz(n+1, 1), enter(n+1);
		vector<array<int, LOG>> anc(n+1), left(n+1), right(n+1);
		int timer = 0;
		auto dfs = [&] (const auto &self, int u, int par) -> void {
			tin[u] = timer++;
			ord.push_back(u);
			for (int i = 1; i < LOG; ++i) anc[u][i] = anc[anc[u][i-1]][i-1];
			for (int v : adj[u]) {
				if (v == par) {
					left[u][0] = timer - tin[u];
					continue;
				}
				anc[v][0] = u;
				self(self, v, u);
				subsz[u] += subsz[v];
			}
			right[u][0] = left[u][0] + n - subsz[u] - 1;
			for (int v : adj[u]) {
				if (v == par) continue;
				enter[v] = tin[v] - tin[u];
				if (v > par) enter[v] += n - subsz[u];
			}
		};
		auto kth = [&] (int u, int k) {
			for (int i = LOG - 1; i >= 0; --i) {
				if (k >= (1 << i)) {
					k -= 1 << i;
					u = anc[u][i];
				}
			}
			return u;
		};
		auto upd = [&] (auto &table, int u, int i) {
			table[u][i] = left[u][i-1] + table[anc[u][i-1]][i-1];
			if (anc[u][i-1] > 1) {
				int x = kth(u, (1 << (i-1)) - 1);
				if (x < anc[x][1]) table[u][i] -= subsz[x];
			}
		};
		auto query = [&] (int u, int x) {
			for (int i = LOG - 1; i >= 0; --i) {
				if (anc[u][i] and x >= left[u][i] and x <= right[u][i]) {
					int y = kth(u, (1 << i) - 1);
					x -= left[u][i];
					if (enter[y] <= x) x += subsz[y];
					u = anc[u][i];
				}
			}
			return ord[x + tin[u] - (x >= left[u][0])*(n - subsz[u])];
		};
		dfs(dfs, 1, 0);
		for (int i = 1; i < LOG; ++i) {
			for (int u = 1; u <= n; ++u) {
				upd(left, u, i);
				upd(right, u, i);
			}
		}

		int q, ans = 0; cin >> q;
		while (q--) {
			int u, x; cin >> u >> x;
			u ^= ans;
			x ^= ans;
			ans = query(u, x);
			cout << ans << '\n';
		}
	}
}

*/