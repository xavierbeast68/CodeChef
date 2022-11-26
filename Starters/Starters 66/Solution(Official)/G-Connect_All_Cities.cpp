//$ URL-> https://www.codechef.com/problems/CNCTCT
//! Pre-requisite->
//^ Kruskal’s algorithm to compute MST
//* https://cp-algorithms.com/graph/mst_kruskal.html

/*
* Author: Sai Panda
* Testers: Hriday, Utkarsh Gupta
* Editorialist: Nishank Suresh
*/

//* Setter's Code->
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define endl "\n"


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T = 1;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        int ans = 0;
        for (int k = 0; k < 30; ++k) {
            vector<int> na;
            int tt = 0, cnt = 0;
            for (auto &x : a) {
                if (x & (1ll << k))
                    tt |= x, cnt++;
                else
                    na.pb(x);
            }
            if (cnt) {
                ans += (cnt - 1) * (1ll << k);
                na.pb(tt);
                swap(a, na);
            }
        }
        if (sz(a) > 1)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}

//* Tester's Code->
/*

// the_hyp0cr1t3
// 22.11.2022 20:41:56

#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

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

struct DSU {
    int N, cnt;
    vector<int> data;
    DSU(int n): N(n), cnt(n), data(n, -1) {}

    int par(int x) {
        return data[x] < 0? x : data[x] = par(data[x]);
    }

    bool merge(int x, int y) {
        x = par(x), y = par(y);
        if(x == y) return false;
        if(-data[x] < -data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        cnt--;
        return true;
    }

};

int main() {
#if __cplusplus > 201703L
    namespace R = ranges;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int64_t sumn = 0;

    int tests = readIntLn(1, 100'000);
    while(tests--) [&] {
        int n = readIntLn(1, 100'000);
        auto a = readVectorInt(n, 0, 1'000'000'000);
        sumn += n;

        DSU dsu(n);
        int64_t ans = 0;
        for(int j = 0; j < 31; j++) {
            int prv = -1;
            for(int i = 0; i < n; i++) {
                if(~a[i] >> j & 1) continue;
                if(~prv)
                    ans += (1LL << j) * dsu.merge(prv, i);
                prv = i;
            }
        }

        cout << (dsu.cnt > 1 ? -1 : ans) << '\n';
    }();

    assert(sumn <= 300'000);

    cerr << "sumn = " << sumn << '\n';

#ifndef W
    readEOF();
#endif

} // ~W

*/

//*Editorialist's Python Code->
/*

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))

    def find(self, a):
        acopy = a
        while a != self.parent[a]:
            a = self.parent[a]
        while acopy != a:
            self.parent[acopy], acopy = a, self.parent[acopy]
        return a

    def union(self, a, b):
        self.parent[self.find(b)] = self.find(a)

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    
    dsu = UnionFind(n)
    merges = 0
    for bit in range(30):
        prv = -1
        for i in range(n):
            if (~a[i] >> bit) & 1: continue
            if prv != -1 and dsu.find(i) != dsu.find(prv):
                ans += 1 << bit
                dsu.union(i, prv)
                merges += 1
            prv = i
    print(ans if merges == n-1 else -1)

*/