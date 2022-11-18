//! Pre-requisites: Computing Binomial Coefficients
//> https://cp-algorithms.com/combinatorics/binomial-coefficients.html#binomial-coefficient-modulo-large-prime

//! multiplicative inverse:
//> https://cp-algorithms.com/algebra/module-inverse.html

//* Setters's Code->

#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ll long long
#define db double
#define el "\n"
#define ld long double
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n;i>=0;i--)
#define rep_a(i,a,n) for(int i=a;i<n;i++)
#define all(ds) ds.begin(), ds.end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef vector< long long > vi;
typedef pair<long long, long long> ii;
typedef priority_queue <ll> pq;
#define o_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 

const ll mod = 1000000007;
const ll INF = (ll)1e18;
const ll MAXN = 1000006;

ll po(ll x, ll n){ 
    ll ans=1;
    while(n>0){ if(n&1) ans=(ans*x)%mod; x=(x*x)%mod; n/=2;}
    return ans;
}

const ll MX=400000;
ll fac[MX], ifac[MX];

void pre(){
 fac[0]=1;
 rep_a(i,1,MX) fac[i]= (i*fac[i-1])%mod;
 rep(i,MX) ifac[i]= po(fac[i], mod-2);
}

ll ncr(ll n, ll r){
 if(r>n || r<0 || n<0) return 0;
 return (fac[n]*((ifac[r]*ifac[n-r])%mod))%mod; 
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T=1;
    cin >> T;
    pre();
    while(T--){

        int n;
        cin>>n;    
        ll ans = 0;

        rep_a(i,1,n+1){
            ll tmp1 = 0;
            if(i < n) tmp1 = (((ncr(n,i+1)*i)%mod)*fac[n-i-1])%mod;

            ll tmp2 = (ncr(n,i)*fac[n-i])%mod;

            ll tmp = (((n-i)*tmp1)%mod + tmp2)%mod;

            tmp *= po(n, mod-2);
            tmp%=mod;

            tmp *= po(fac[n], mod-2);
            tmp%=mod;

            tmp*=i;
            tmp%=mod;

            ans += tmp;
        }

        ans%=mod;

        cout<<ans<<el;
    
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
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

constexpr long long mod = (int) 1e9 + 7;
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
    int tt = in.readInt(1, 1e3);
    in.readEoln();
    int sn = 0;
    while (tt--) {
        int n = in.readInt(1, 2e5);
        in.readEoln();
        mint ans = 0;
        C(n, 0);
        for (int i = 1; i <= n; i++) {
            ans += C(n, i) * fact[n - i] * (n - i + 1);
        }
        ans *= finv[n];
        ans /= n;
        cout << ans << '\n';
    }
    assert(sn <= 2e5);
    in.readEof();
    return 0;
}

*/

//* Editorialist's Python code->
/*

mod = 10**9 + 7
fac = [1]
ifac = [1]
for i in range(1, 200005):
	fac.append(i * fac[i-1])
	fac[i] %= mod
	ifac.append(pow(fac[i], mod-2, mod))
def C(n, r):
	if r < 0 or n < r: return 0
	return (fac[n] * ifac[r] * ifac[n-r])%mod

for _ in range(int(input())):
	n = int(input())
	ans = 0
	for i in range(1, n+1):
		ans += i * fac[n-i] * (C(n, i) + i*C(n, i+1))
		ans %= mod
	ans *= pow(fac[n] * n, mod-2, mod)
	print(ans % mod)

*/