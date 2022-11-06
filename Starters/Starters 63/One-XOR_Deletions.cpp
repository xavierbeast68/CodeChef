//* setter's code-

#include "bits/stdc++.h"
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using ll = long long int;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> freq(n+10);
		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			++freq[x];
		}
		int ans = n - 1;
		for (int i = 0; i <= n; ++i) {
			ans = min(ans, n - freq[i] - freq[i^1]);
		}
		cout << ans << '\n';
	}
}