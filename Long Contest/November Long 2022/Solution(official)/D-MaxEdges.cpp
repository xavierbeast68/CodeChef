//* Setter's Code->

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007
#define mp make_pair
 
ll fact[200005];
 
ll powermod(ll x,ll y){
  if(y==0) return 1;
  ll temp = powermod( x,y/2 )%mod;
  if( y%2 ){
    return (((temp*temp)%mod)*x%mod);
  }
  return (temp*temp)%mod;
}
 
ll power(ll x,ll y){
  if(y==0) return 1;
  ll temp = power( x,y/2 );
  if( y%2 ){
    return (((temp*temp))*x);
  }
  return (temp*temp);
}
 
int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}
 
ll inv(ll a, ll p){
	return powermod(a,mod-2);
}
 
ll nCr(ll n, ll r, ll p){
	if(r > n) return 0;
	ll t1 = fact[n];
	ll t2 = inv(fact[r],p);
	ll t3 = inv(fact[n-r],p);
 
	return (((t1*t2)%p)*t3)%p;
}
 
 
void solve(){
  int i, j, n, l, k;
  cin >> n >> l >> k;
  //cout << "3 4\n";
  //return;
  if(l+k <= n){
    int ans = n*(n-1)/2;
    ans -= ((l*(l-1)/2) + (k*(k-1)/2));
    //ans %= mod;
    cout << ans << "\n";
  }
  else{
    int x = l + k - n;
    n -= x;
    l -= x;
    k -= x;
    int ans = n*(n-1)/2;
    ans -= ((l*(l-1)/2) + (k*(k-1)/2));
    //ans %= mod;
    cout << ans << "\n";
  }
  return;
}
 
signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  cin>>t;
  //srand(time(0));
  // fact[0]=1;
  // for(int i=1;i<200001;i++){
  //   fact[i]=i*fact[i-1];
  //   fact[i]%=mod;
  // }
  while (t--){
    solve();
  }
  //cout << "3 4\n";
  return 0;
}

//* Tester's code->
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

int main() {
    input_checker in;
    int tt = in.readInt(1, 1e5);
    in.readEoln();
    while (tt--) {
        int n = in.readInt(2, 1e9);
        in.readSpace();
        int k = in.readInt(1, n - 1);
        in.readSpace();
        int l = in.readInt(1, n - 1);
        in.readEoln();
        long long ans = 0;
        if ((k + l) > n) {
            int x = k + l - n;
            ans = (k - x) * 1LL * (l - x);
        } else {
            ans = k * 1LL * (n - k) + (n - k - l) * 1LL * l + (n - k - l) * 1LL * (n - k - l - 1) / 2;
        }
        cout << ans << '\n';
    }
    in.readEof();
    return 0;
}

*/

//* Editorialist's Python Code->
/*

for _ in range(int(input())):
    n, k, l = map(int, input().split())
    if k+l > n:
        common = k+l-n
        n -= common
        k -= common
        l -= common
    print(k*(n-k) + (n-k-l)*(n-k-l-1)//2 + (n-k-l)*l)

*/