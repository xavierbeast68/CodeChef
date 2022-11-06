//* Setter's code->

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
		int n, m; cin >> n >> m;
		vector grid(n, vector(m, 0));
		for (auto &row : grid) for (auto &x : row) cin >> x;
		vector dp(n, vector(m, 0));
		for (int i = n-1; i >= 0; --i) {
			for (int j = m-1; j >= 0; --j) {
				if (i == n-1 and j == m-1) dp[i][j] = grid[i][j];
				else if (i == n-1) dp[i][j] = max(grid[i][j], dp[i][j+1]);
				else if (j == m-1) dp[i][j] = max(grid[i][j], dp[i+1][j]);
				else {
					if ((i+j)%2 == 0) { // Becky
						dp[i][j] = max(grid[i][j], min(dp[i+1][j], dp[i][j+1]));
					}
					else { // Anya
						if (grid[i+1][j] > grid[i][j+1]) dp[i][j] = max(grid[i][j], dp[i+1][j]);
						else dp[i][j] = max(grid[i][j], dp[i][j+1]);
					}
				}
			}
		}
		cout << dp[0][0] << '\n';
	}
}

//* Tester's Code->
/*

#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct input_checker {
    string buffer;
    int pos;

    const string all = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const string number = "0123456789";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string lower = "abcdefghijklmnopqrstuvwxyz";

    input_checker() {
        pos = 0;
        while (true) {
            int c = cin.get();
            if (c == -1) {
                break;
            }
            buffer.push_back((char) c);
        }
    }

    int nextDelimiter() {
        int now = pos;
        while (now < (int) buffer.size() && buffer[now] != ' ' && buffer[now] != '\n') {
            now++;
        }
        return now;
    }

    string readOne() {
        assert(pos < (int) buffer.size());
        int nxt = nextDelimiter();
        string res;
        while (pos < nxt) {
            res += buffer[pos];
            pos++;
        }
        // cerr << res << endl;
        return res;
    }

    string readString(int minl, int maxl, const string& pattern = "") {
        assert(minl <= maxl);
        string res = readOne();
        assert(minl <= (int) res.size());
        assert((int) res.size() <= maxl);
        for (int i = 0; i < (int) res.size(); i++) {
            assert(pattern.empty() || pattern.find(res[i]) != string::npos);
        }
        return res;
    }

    int readInt(int minv, int maxv) {
        assert(minv <= maxv);
        int res = stoi(readOne());
        assert(minv <= res);
        assert(res <= maxv);
        return res;
    }

    long long readLong(long long minv, long long maxv) {
        assert(minv <= maxv);
        long long res = stoll(readOne());
        assert(minv <= res);
        assert(res <= maxv);
        return res;
    }

    void readSpace() {
        assert((int) buffer.size() > pos);
        assert(buffer[pos] == ' ');
        pos++;
    }

    void readEoln() {
        assert((int) buffer.size() > pos);
        assert(buffer[pos] == '\n');
        pos++;
    }

    void readEof() {
        assert((int) buffer.size() == pos);
    }
};

template <long long mod>
struct modular {
    long long value;
    modular(long long x = 0) {
        value = x % mod;
        if (value < 0) value += mod;
    }
    modular& operator+=(const modular& other) {
        if ((value += other.value) >= mod) value -= mod;
        return *this;
    }
    modular& operator-=(const modular& other) {
        if ((value -= other.value) < 0) value += mod;
        return *this;
    }
    modular& operator*=(const modular& other) {
        value = value * other.value % mod;
        return *this;
    }
    modular& operator/=(const modular& other) {
        long long a = 0, b = 1, c = other.value, m = mod;
        while (c != 0) {
            long long t = m / c;
            m -= t * c;
            swap(c, m);
            a -= t * b;
            swap(a, b);
        }
        a %= mod;
        if (a < 0) a += mod;
        value = value * a % mod;
        return *this;
    }
    friend modular operator+(const modular& lhs, const modular& rhs) { return modular(lhs) += rhs; }
    friend modular operator-(const modular& lhs, const modular& rhs) { return modular(lhs) -= rhs; }
    friend modular operator*(const modular& lhs, const modular& rhs) { return modular(lhs) *= rhs; }
    friend modular operator/(const modular& lhs, const modular& rhs) { return modular(lhs) /= rhs; }
    modular& operator++() { return *this += 1; }
    modular& operator--() { return *this -= 1; }
    modular operator++(int) {
        modular res(*this);
        *this += 1;
        return res;
    }
    modular operator--(int) {
        modular res(*this);
        *this -= 1;
        return res;
    }
    modular operator-() const { return modular(-value); }
    bool operator==(const modular& rhs) const { return value == rhs.value; }
    bool operator!=(const modular& rhs) const { return value != rhs.value; }
    bool operator<(const modular& rhs) const { return value < rhs.value; }
};
template <long long mod>
string to_string(const modular<mod>& x) {
    return to_string(x.value);
}
template <long long mod>
ostream& operator<<(ostream& stream, const modular<mod>& x) {
    return stream << x.value;
}
template <long long mod>
istream& operator>>(istream& stream, modular<mod>& x) {
    stream >> x.value;
    x.value %= mod;
    if (x.value < 0) x.value += mod;
    return stream;
}

constexpr long long mod = 998244353;
using mint = modular<mod>;

mint power(mint a, long long n) {
    mint res = 1;
    while (n > 0) {
        if (n & 1) {
            res *= a;
        }
        a *= a;
        n >>= 1;
    }
    return res;
}

vector<mint> fact(1, 1);
vector<mint> finv(1, 1);

mint C(int n, int k) {
    if (n < k || k < 0) {
        return mint(0);
    }
    while ((int) fact.size() < n + 1) {
        fact.emplace_back(fact.back() * (int) fact.size());
        finv.emplace_back(mint(1) / fact.back());
    }
    return fact[n] * finv[k] * finv[n - k];
}

int main() {
    input_checker in;
    int tt = in.readInt(1, 3e4);
    in.readEoln();
    int sn = 0;
    while (tt--) {
        int h = in.readInt(1, 5e5);
        in.readSpace();
        int w = in.readInt(1, 5e5);
        in.readEoln();
        assert(1LL * h * w <= 5e5);
        sn += h * w;
        vector<vector<int>> a(h, vector<int>(w));
        vector<int> b;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                a[i][j] = in.readInt(1, h * w);
                (j == w - 1 ? in.readEoln() : in.readSpace());
                b.emplace_back(a[i][j]);
            }
        }
        sort(b.begin(), b.end());
        for (int i = 0; i < h * w; i++) {
            assert(b[i] == i + 1);
        }
        vector<vector<int>> dp(h, vector<int>(w, h * w + 10));
        dp[0][0] = a[0][0];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                dp[i][j] = max(dp[i][j], a[i][j]);
                if (i == h - 1 && j == w - 1) {
                    continue;
                } else if (i == h - 1) {
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
                } else if (j == w - 1) {
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
                } else if ((i + j) % 2 == 1) {  // anya
                    if (a[i][j + 1] > a[i + 1][j]) {
                        dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
                    } else {
                        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
                    }
                } else {  // becky
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
                }
            }
        }
        cout << dp[h - 1][w - 1] << endl;
    }
    assert(sn <= 5e5);
    in.readEof();
    return 0;
}

*/