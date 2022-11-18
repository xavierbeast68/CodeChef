//*  Setter's code (C++)->
#include<bits/stdc++.h>
#define ll long long int
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define db double
#define mp make_pair
#define endl "\n"
#define f first
#define se second
#define all(x) x.begin(),x.end()
#define vll vector<ll>
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

const int MOD = 1e9 + 7;

ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}
ll lcm(ll x, ll y) { ll res = x / __gcd(x, y); return (res * y);}


#define int ll
void dfs(int src, int par, vector<int> &a, vector<vector<int>> &v, vector<vector<int>> &values, vector<int> &parent) {

	parent[src] = par;
	for (int &i : v[src]) {
		if (i ^ par) {
			dfs(i, src, a, v, values, parent);
		}
	}

	int curr = src;
	int val = a[src];
	while (curr != -1 and val > 0) {
		values[curr].push_back(val);
		curr = parent[curr];
		val >>= 1;
	}
}

int32_t main()
{

	quick;
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<vector<int>> v(n);

		for (int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			x--, y--;
			v[x].push_back(y);
			v[y].push_back(x);
		}

		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		vector<vector<int>> values(n);
		vector<int> parent(n, -1);
		dfs(0, -1, a, v, values, parent);

		vector<int> ans(n);

		for (int &i : values[0]) {
			ans[0] += i;
		}

		const int maxA = 1e6 + 5;

		const int N = log2(maxA) + 3;

		vector<vector<int>> moveNodes(n, vector<int> (N));

		for (int i = 0; i < n; i++) {
			for (int &j : values[i]) {
				for (int k = 0; k < N; k++) {
					int val = (j >> k);
					moveNodes[i][k] += val;
					if (val == 0) break;
				}
			}
		}

		for (int i = 1; i < n; i++)  {

			ans[i] = moveNodes[i][0];
			int last = i;
			int curr = parent[i];
			for (int j = 1; j < N - 1 and curr != -1; j++) {
				int val = (moveNodes[curr][j] - moveNodes[last][j + 1]);
				ans[i] += val;
				last = curr;
				curr = parent[curr];
			}
		}


		for (int i = 0; i < n; i++) cout << ans[i] << " ";
		cout << endl;


	}



	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
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

struct dsu {
    int n;
    vector<int> p;
    vector<int> sz;

    dsu(int _n) : n(_n) {
        p = vector<int>(n);
        iota(p.begin(), p.end(), 0);
        sz = vector<int>(n, 1);
    }

    inline int get(int x) {
        if (p[x] == x) {
            return x;
        } else {
            return p[x] = get(p[x]);
        }
    }

    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return false;
        }
        p[x] = y;
        sz[y] += sz[x];
        return true;
    }

    inline bool same(int x, int y) {
        return (get(x) == get(y));
    }

    inline int size(int x) {
        return sz[get(x)];
    }

    inline bool root(int x) {
        return (x == get(x));
    }
};

int main() {
    input_checker in;
    int tt = in.readInt(1, 1e4);
    in.readEoln();
    int sn = 0;
    while (tt--) {
        int n = in.readInt(1, 5e4);
        in.readEoln();
        sn += n;
        vector<vector<int>> g(n);
        dsu uf(n);
        for (int i = 0; i < n - 1; i++) {
            int x = in.readInt(1, n);
            in.readSpace();
            int y = in.readInt(1, n);
            in.readEoln();
            x--;
            y--;
            g[x].emplace_back(y);
            g[y].emplace_back(x);
            uf.unite(x, y);
        }
        assert(uf.size(0) == n);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = in.readInt(1, 1e6);
            (i == n - 1 ? in.readEoln() : in.readSpace());
        }
        vector<int> pv(n, -1);
        {
            function<void(int, int)> Dfs = [&](int v, int p) {
                for (int to: g[v]) {
                    if (to == p) {
                        continue;
                    }
                    pv[to] = v;
                    Dfs(to, v);
                }
            };
            Dfs(0, -1);
        }
        vector s(n, vector(20, vector<long long>(20)));
        for (int i = 0; i < n; i++) {
            int v = i;
            for (int j = 0; j < 20; j++) {
                if (v == -1) {
                    break;
                }
                for (int k = j; k < 20; k++) {
                    s[v][j][k] += a[i] >> k;
                }
                v = pv[v];
            }
        }
        for (int i = 0; i < n; i++) {
            long long ans = 0;
            for (int j = 0; j < 20; j++) {
                ans += s[i][j][j];
            }
            int last = i;
            int v = pv[i];
            for (int j = 1; j < 20; j++) {
                if (v == -1) {
                    break;
                }
                for (int k = 0; j + k < 20; k++) {
                    ans += s[v][k][j + k];
                    if (k != 0) {
                        ans -= s[last][k - 1][j + k];
                    }
                }
                last = v;
                v = pv[v];
            }
            cout << ans << " \n"[i == n - 1];
        }
    }
    assert(sn <= 5e4);
    in.readEof();
    return 0;
}

*/

//* Tester's Code->
/*

//Utkarsh.25dec
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
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
int par[N];
void checktree(int curr)
{
    vis[curr]=1;
    for(auto it:adj[curr])
    {
        if(vis[it])
            continue;
        par[it]=curr;
        checktree(it);
    }
}
int sumN=0;
void solve()
{
    int n=readInt(1,50000,'\n');
    sumN+=n;
    assert(sumN<=50000);
    for(int i=1;i<=n;i++)
    {
        adj[i].clear();
        vis[i]=0;
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        u=readInt(1,n,' ');
        v=readInt(1,n,'\n');
        assert(u!=v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    checktree(1);
    for(int i=1;i<=n;i++)
    {
        assert(vis[i]==1);
        vis[i]=0;
    }
    int A[n+1];
    memset(A,0,sizeof(A));
    for(int i=1;i<=n;i++)
    {
        if(i==n)
            A[i]=readInt(1,1000000,'\n');
        else
            A[i]=readInt(1,1000000,' ');
    }
    vector <int> vals[n+1];
    for(int i=1;i<=n;i++)
    {
        int curr=i;
        for(int j=0;j<=22;j++)
        {
            if((A[i]/(1<<j))>0)
                vals[curr].pb(A[i]/(1<<j));
            curr=par[curr];
            if(curr==0)
                break;
        }
    }
    ll shifts[n+1][23];
    memset(shifts,0,sizeof(shifts));
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=22;j++)
        {
            for(auto it:vals[i])
                shifts[i][j]+=(it/(1<<j));
        }
    }
    ll ans[n+1];
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=n;i++)
    {
        ans[i]=shifts[i][0];
        int x=i;
        int y=par[i];
        int cnt=1;
        while(y!=0)
        {
            if(cnt>=21)
                break;
            ans[i]+=(shifts[y][cnt]-shifts[x][cnt+1]);
            x=par[x];
            y=par[y];
            cnt++;
        }
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<'\n';
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int T=readInt(1,50000,'\n');
    while(T--)
        solve();
    assert(getchar()==-1);
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

*/