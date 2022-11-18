//* Setter's Code->
#include <bits/stdc++.h>
#define int long long int
using namespace std;

#define mod 1000000007

int power(int a , int b) {
	if(b == 0)
		return 1;
	int res = power(a , b>>1);
	if(b & 1)
		return (res * res % mod) * a % mod;
	return res * res % mod;
}

signed main() {

	int t;
	cin>>t;
	while(t--) {
		int n , k;
		cin>>n>>k;
		vector<int> a(k);
		for(int i=0;i<n;i++) {
			int x;
			cin>>x;
			a[x % k]++;
		}
		// for(auto &i: a)
		// 	cout<<i<<" ";
		// cout<<endl;
		int ans = 1;
		// cout<<power(2 , 2)<<endl;
		for(int i=1;i<(k+1)/2;i++) {
			int c = (power(2 , a[i]) + power(2 , a[k-i]) - 1);
			ans = ans * c % mod;
		}
		if(k % 2 == 0) {
			ans = ans * (a[k/2] + 1) % mod;
		}
		ans = ans * (a[0]+1) % mod;
		cout<<ans<<endl;
	}
	return 0;
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

    string readString(int minl, int maxl, const string &pattern = "") {
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

const long long mod = (int) 1e9 + 7;

struct mint {
    long long value;

    mint(long long x = 0) {
        value = x % mod;
        if (value < 0) value += mod;
    }

    mint &operator+=(const mint &other) {
        if ((value += other.value) >= mod) value -= mod;
        return *this;
    }

    mint &operator-=(const mint &other) {
        if ((value -= other.value) < 0) value += mod;
        return *this;
    }

    mint &operator*=(const mint &other) {
        value = value * other.value % mod;
        return *this;
    }

    mint &operator/=(const mint &other) {
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

    friend mint operator+(const mint &lhs, const mint &rhs) { return mint(lhs) += rhs; }

    friend mint operator-(const mint &lhs, const mint &rhs) { return mint(lhs) -= rhs; }

    friend mint operator*(const mint &lhs, const mint &rhs) { return mint(lhs) *= rhs; }

    friend mint operator/(const mint &lhs, const mint &rhs) { return mint(lhs) /= rhs; }

    mint &operator++() { return *this += 1; }

    mint &operator--() { return *this -= 1; }

    mint operator++(int) {
        mint result(*this);
        *this += 1;
        return result;
    }

    mint operator--(int) {
        mint result(*this);
        *this -= 1;
        return result;
    }

    mint operator-() const { return mint(-value); }

    bool operator==(const mint &rhs) const { return value == rhs.value; }

    bool operator!=(const mint &rhs) const { return value != rhs.value; }

    bool operator<(const mint &rhs) const { return value < rhs.value; }
};

string to_string(const mint &x) {
    return to_string(x.value);
}

ostream &operator<<(ostream &stream, const mint &x) {
    return stream << x.value;
}

istream &operator>>(istream &stream, mint &x) {
    stream >> x.value;
    x.value %= mod;
    if (x.value < 0) x.value += mod;
    return stream;
}

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
        finv.emplace_back(1 / fact.back());
    }
    return fact[n] * finv[k] * finv[n - k];
}

int main() {
    input_checker in;
    int tt = in.readInt(1, 1e4);
    in.readEoln();
    int sn = 0, sk = 0;
    int mn = 2e9, mx = -1;
    while (tt--) {
        int n = in.readInt(1, 1e5);
        in.readSpace();
        int k = in.readInt(1, 5e5);
        in.readEoln();
        sn += n;
        sk += k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = in.readInt(1, 1e9);
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
            a[i] %= k;
            (i == n - 1 ? in.readEoln() : in.readSpace());
        }
        vector<int> c(k);
        for (int i = 0; i < n; i++) {
            c[a[i]]++;
        }
        mint ans = c[0] + 1;
        for (int i = 1; i < k; i++) {
            int j = k - i;
            if (i == j) {
                ans *= c[i] + 1;
            } else if (i < j) {
                ans *= power(2, c[i]) + power(2, c[j]) - 1;
            }
        }
        cout << ans << '\n';
    }
    assert(sn <= 1e6);
    assert(sk <= 1e6);
    cerr << sn + sk << " " << mn << " " << mx << endl;
    in.readEof();
    return 0;
}
*/

//* editorialist's Python Code->
/*

mod = 10**9 + 7
for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    freq = [0]*k
    for x in a:
        freq[x%k] += 1
    ans = 1
    for i in range(k):
        if i == 0 or 2*i == k:
            ans *= 1 + freq[i]
        else:
            if i > k-i: break
            ans *= pow(2, freq[i], mod) + pow(2, freq[k-i], mod) - 1
        ans %= mod
    print(ans%mod)

*/