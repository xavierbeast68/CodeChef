/**
 * @author xavierbeast68
 * Problem Name- Red Green Grids ( Codechef Starters 60)
 * Problem Link- https://www.codechef.com/submit/REDGREEN
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */

//* Tester's Solution
/*
#include <bits/stdc++.h>
using namespace std;
#define maxn 10007
#define mod 998244353

long long int fact[maxn], ifact[maxn];

long long int mpow(long long int a, long long int b) {
    long long int res = 1;
    while(b) {
        if(b&1) res *= a, res %= mod;
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return res;
}


void pre() {
    fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
    for(int i = 2; i < maxn; i++) fact[i] = fact[i - 1]*i, fact[i] %= mod;
    for(int i = 2; i < maxn; i++) ifact[i] = ifact[i - 1]*mpow(i, mod - 2), ifact[i] %= mod;
}

long long int comb(long long int a, long long int b) {
    if(b == 0) return 1LL;
    long long int ans = fact[a];
    ans *= ifact[b];
    ans %= mod;
    ans *= ifact[a - b];
    ans %= mod;
    return ans;
}

int main() {
    pre();
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        if((n + m - 1)&1) cout << "0\n";
        else {
            long long int paths = comb(n + m - 2, m - 1);
            paths *= ((fact[n + m - 1]*((ifact[(n + m - 1)/2]*ifact[(n + m - 1)/2])%mod))%mod);
            paths %= mod;
            paths *= mpow(2, n*m - (n + m - 1));
            paths %= mod;
            cout << paths << "\n";
        }
    }
    return 0;
}
*/