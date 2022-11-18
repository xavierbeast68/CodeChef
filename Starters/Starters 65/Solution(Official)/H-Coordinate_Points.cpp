//* Setter's code (C++)->

#include<bits/stdc++.h>
#define int long long int
#define endl "\n"
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

signed main()
{
    quick;

    int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	int a = 0, b = 0, c = 0, d = 0, o = 0;
    	while(n--){
    		int x , y;
    		cin>>x>>y;
    		if(x==0 && y==0){
    			o++;
    		}
    		else if(y>0)
    			c++;
    		else if(y<0)
    			d++;
    		else if(x>0)
    			a++;
    		else
    			b++;
    	}

    	// cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

    	int k = a+b+o;
    	int A = k%2 ? k/2*(k/2+1) : k*k / 4;

    	k = c+d+o;
    	int B = k%2 ? k/2*(k/2+1) : k*k / 4;

    	int X = A - a*b;
    	int Y = B - c*d;

    	// cout<<A<<" "<<B<<endl;

    	int ans = A + B - min(a*b , Y) - min(c*d , X);
    	X -= min(c*d , X);
    	Y -= min(a*b , Y);

    	ans -= min(X , Y);

    	ans = max(ans , max({min(a , c) , min(a , d) , min(b , d) , min(b , c)}));

    	cout<<ans<<endl;
    }
    
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

//* Tester's code (C++)->
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

int main() {
    input_checker in;
    int tt = in.readInt(1, 1e5);
    in.readEoln();
    int sn = 0;
    while (tt--) {
        int n = in.readInt(2, 1e6);
        in.readEoln();
        sn += n;
        set<pair<int, int>> st;
        int px = 0, nx = 0, py = 0, ny = 0;
        for (int i = 0; i < n; i++) {
            int x = in.readInt(-1e9, 1e9);
            in.readSpace();
            int y = in.readInt(-1e9, 1e9);
            in.readEoln();
            assert(x == 0 || y == 0);
            st.emplace(x, y);
            if (x > 0) {
                px++;
            }
            if (x < 0) {
                nx++;
            }
            if (y > 0) {
                py++;
            }
            if (y < 0) {
                ny++;
            }
        }
        assert(n == (int) st.size());
        long long ans = min(max(px, nx), max(py, ny));
        ans = max(ans, px * 1LL * nx + py * 1LL * ny);
        int cx = px + nx, cy = py + ny;
        if (cx + cy == n - 1) {
            cx++;
            cy++;
        }
        ans = max(ans, (cx - cx / 2) * 1LL * (cx / 2));
        ans = max(ans, (cy - cy / 2) * 1LL * (cy / 2));
        cout << ans << '\n';
    }
    assert(sn <= 1e6);
    in.readEof();
    return 0;
}
*/

//* Tester's code (C++)->
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
int sumN=0;
void solve()
{
    int n=readInt(2,1000000,'\n');
    sumN+=n;
    assert(sumN<=1000000);
    set <pair<int,int>> s;
    ll cntx=0,cnty=0,posx=0,negx=0,posy=0,negy=0;
    for(int i=1;i<=n;i++)
    {
        ll x,y;
        x=readInt(-1000000000,1000000000,' ');
        y=readInt(-1000000000,1000000000,'\n');
        s.insert(mp(x,y));
        assert(x==0 || y==0);
        if(x==0)
            cnty++;
        if(y==0)
            cntx++;
        if(x<0)
            negx++;
        if(x>0)
            posx++;
        if(y<0)
            negy++;
        if(y>0)
            posy++;
    }
    assert(s.size()==n);
    ll ans=0;
    ans=max(ans,min(max(negx,posx),max(negy,posy)));
    ans=max(ans,posx*negx+posy*negy);
    ll A=((cntx+1)/2)*(cntx/2);
    ll B=((cnty+1)/2)*(cnty/2);
    ans=max(ans,max(A,B));
    cout<<ans<<'\n';
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
    while(T--)
        solve();
    assert(getchar()==-1);
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
*/