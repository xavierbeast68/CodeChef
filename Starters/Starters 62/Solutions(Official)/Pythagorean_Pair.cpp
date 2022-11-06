// Preparer's Code ->
//Utkarsh.25dec
#include <bits/stdc++.h>
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
int avail[N];
pair<ll,ll> good[N];
int issq[N];
int sqrtval[N];
void solve()
{
    ll n=readInt(1,(ll)100000000*10000000,'\n');
    ll tmp=n;
    while(tmp%2==0)
        tmp/=2;
    assert(tmp<=100000);
    if(avail[tmp]==0)
        cout<<-1<<'\n';
    else
    {
        ll a=good[tmp].first;
        ll b=good[tmp].second;
        while(tmp!=n)
        {
            ll c=a+b;
            ll d=abs(a-b);
            a=c;
            b=d;
            tmp*=2;
        }
        cout<<a<<' '<<b<<'\n';
    }
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
    for(int i=0;i<400;i++)
    {
        issq[i*i]=1;
        sqrtval[i*i]=i;
    }
    for(int n=1;n<=100000;n++)
    {
        for(int a=0;a<=1000;a++)
        {
            if(a*a>n)
                break;
            if(issq[n-a*a]==1)
            {
                ll b=sqrtval[n-a*a];
                good[n]=mp(a,b);
                avail[n]=1;
                break;
            }
        }
    }
    while(T--)
        solve();
    assert(getchar()==-1);
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}





// Tester's Code ->

#include <bits/stdc++.h>
using namespace std;

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

int main() {
    input_checker in;
    int tt = in.readInt(1, 1e5);
    in.readEoln();
    while (tt--) {
        long long n = in.readLong(1, 1e15);
        in.readEoln();
        long long m = 1;
        while (n % 2 == 0) {
            n /= 2;
            m *= 2;
        }
        assert(n <= 1e5);
        if (__builtin_ctzll(m) % 2 == 1) {
            m /= 2;
            n *= 2;
        }
        m = llround(sqrtl(m));
        int a = -1;
        for (int i = 0; i * i <= n; i++) {
            int j = (int) llround(sqrtl(n - i * i));
            if (i * i + j * j == n) {
                a = i;
                break;
            }
        }
        if (a == -1) {
            cout << -1 << '\n';
        } else {
            cout << a * m << " " << llround(sqrtl(n - a * a)) * m << '\n';
        }
    }
    in.readEof();
    return 0;
}






// Editor's Code ->

#include "bits/stdc++.h"
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using ll = long long int;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	const int mx = 2e5 + 10;

	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		ll mul = 1;
		while (n > mx) {
			n /= 4;
			mul *= 2;
		}
		bool done = false;
		for (int i = 0; i*i <= n; ++i) {
			int rem = n - i*i;
			int s = sqrtl(rem);
			while (s*s > rem) --s;
			while ((s+1)*(s+1) <= rem) ++s;
			if (s*s == rem) {
				cout << mul*i << ' ' << mul*s << '\n';
				done = true;
				break;
			}
		}
		if (!done) cout << -1 << '\n';
	}
}