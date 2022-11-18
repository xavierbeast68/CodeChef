//* Setter's Code->

#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long int

#define ld long double
#define forn(i, x, n) for (ll i = x; i < n; i++)
#define fornb(i, n, x) for (ll i = n; i >= x; i--)
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define MOD 1000000007
#define MAX 300007
#define endl "\n" // REMOVE in lleraction problem
#define debug cout << "K"


ll checkifdivof3(string &s)
{
    ll n = s.size();
    ll ev = 0,odd =0;
    forn(i , 0 ,n)
    {
        if(i%2==0){
            if(s[i]=='1')
            ev++;
        }
        else
        {
            if(s[i]=='1')
            odd++;
        }

    }

    ll a= abs(ev-odd)%3;
    if(a==0)
    return 1;
    return 0;
}


string evodd(string &s , ll &mov)
{
    
if(checkifdivof3(s))
{
    mov =0;
    return s;

}


    map<char ,ll> mp;
    ll n = s.size();
    string tmp =s;

    ll prev =-1 ,after=-1;
    ll diff =LLONG_MAX;

    forn(i ,0 ,n)
    {
        if(i%2==0 && s[i]=='1' && mp['0']!=0)
        {

            ll tmp = i+1 - mp['0'];

            if(tmp<diff)
            {
                diff =tmp;
                prev =mp['0'];
                after = i+1;
            }
            
        }
        else
        if(i%2==1 && s[i]=='0' && mp['1']!=0)
        {
            ll tmp = i+1 - mp['1'];

            if(tmp<diff)
            {
                diff =tmp;
                prev =mp['1'];
                after = i+1;
            }

        }

        if(i%2==0 && s[i]=='1')
        mp[s[i]] = i+1;
        if(i%2==1 && s[i]=='0')
        mp[s[i]] = i+1;


        
    }

    if(prev-1 >=0 && after-1>=0)
    {
        swap(tmp[prev-1] , tmp[after-1]);
        mov = after - prev;
    }
    else
    mov =LLONG_MAX;

    // cout<<prev-1<<" "<<after-1<<endl;

    return tmp;
}




string oddev(string &s , ll &mov)
{
    
if(checkifdivof3(s))
{
    mov =0;
    return s;

}


    map<char ,ll> mp;
    ll n = s.size();
    string tmp =s;

    ll prev =-1 ,after=-1;
    ll diff =LLONG_MAX;

    forn(i ,0 ,n)
    {
        if(i%2==1 && s[i]=='1' && mp['0']!=0)
        {

            ll tmp = i+1 - mp['0'];

            if(tmp<diff)
            {
                diff =tmp;
                prev =mp['0'];
                after = i+1;
            }
            
        }
        else
        if(i%2==0 && s[i]=='0' && mp['1']!=0)
        {
            ll tmp = i+1 - mp['1'];

            if(tmp<diff)
            {
                diff =tmp;
                prev =mp['1'];
                after = i+1;
            }

        }

        if(i%2==0 && s[i]=='0')
        mp[s[i]] = i+1;
        if(i%2==1 && s[i]=='1')
        mp[s[i]] = i+1;


        
    }

    if(prev-1 >=0 && after-1>=0)
    {
        swap(tmp[prev-1] , tmp[after-1]);
        
    mov = after - prev;
    }
    else
    mov = LLONG_MAX;

    // cout<<prev-1<<" "<<after-1<<endl;

    return tmp;
}



int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ofstream off;
    off.open("output2.out");
    ifstream iff;
    iff.open("input2.in");


    ll t = 1;
    cin>>t;

    while (t--)
    {
        
        string s;
        cin>>s;


        if(checkifdivof3(s))
        {
            cout<<0<<endl;
            continue;
        }
        ll ans = LLONG_MAX;
        ll mov  = 0 , mov2 = 0;
        string h =s;

        string tmp = evodd(h , mov);
        string tmp2 = evodd(tmp , mov2);

        if(mov==LLONG_MAX || mov2==LLONG_MAX)
        {

        }
        else
        {
            ans = mov + mov2;
        }

        
        ll mov3  = 0 , mov4 = 0;

        string tmp3 = oddev(h , mov3);
        string tmp4 = oddev(tmp3 , mov4);

        if(mov3==LLONG_MAX || mov4==LLONG_MAX)
        {

        }
        else
        {
            ans =min(ans ,mov3 + mov4);
        }

        if(ans==LLONG_MAX)
        cout<<-1<<endl;
        else
        cout<<ans<<endl;
    }
}

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
int sumN=0;
void solve()
{
    string s=readString(1,300000,'\n');
    int n=s.length();
    sumN+=n;
    assert(sumN<=300000);
    for(int i=0;i<n;i++)
    	assert(s[i]=='0' || s[i]=='1');
    ll rem=0;
    int cnt0=0,cnt1=0;
    for(int i=0;i<n;i++)
    {
    	rem*=2;
    	if(s[i]=='1')
    	{
    		cnt1++;
    		rem++;
    	}
    	else
    		cnt0++;
    	rem%=3;
    }
    if(rem==0)
    {
    	cout<<0<<'\n';
    	return;
    }
    if(min(cnt1,cnt0)==0)
    {
    	cout<<-1<<'\n';
    	return;
    }
    if(min(cnt1,cnt0)==1)
    {
    	for(int i=0;i<n-1;i++)
    	{
    		if(s[i]!=s[i+1])
    		{
    			int pos;
    			if(s[i]=='1')
    				pos=n-i;
    			else
    				pos=n-(i+1);
    			pos%=2;
	    		if(rem==2 && pos==1)
	    			cout<<1<<'\n';
	    		else if(rem==1 && pos==0)
	    			cout<<1<<'\n';
	    		else
	    			cout<<-1<<'\n';
	    		return;
    		}
    	}
    }
    vector <int> positions;
    int mark[2];
    memset(mark,0,sizeof(mark));
    for(int i=0;i<n-1;i++)
    {
    	if(s[i]!=s[i+1])
    	{
    		if(s[i]=='1')
    			positions.pb((n-i)%2);
    		else
    			positions.pb((n-(i+1))%2);
    	}
    }
    for(auto it:positions)
    	mark[it]=1;
    if(positions.size()==1)
    {
    	int pos=positions[0];
    	if(rem==2 && pos==1)
			cout<<1<<'\n';
		else if(rem==1 && pos==0)
			cout<<1<<'\n';
		else
			cout<<3<<'\n';
		return;
    }
    if(rem==1)
   	{
   		// take even placed 1 to odd position
   		if(mark[0]==1)
   			cout<<1<<'\n';
   		else
   			cout<<2<<'\n';
   		return;
   	}
   	if(rem==2)
   	{
   		// take even placed 1 to odd position
   		if(mark[1]==1)
   			cout<<1<<'\n';
   		else
   			cout<<2<<'\n';
   		return;
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
    while(T--)
        solve();
    assert(getchar()==-1);
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

*/

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

int main() {
    input_checker in;
    int tt = in.readInt(1, 1e5);
    in.readEoln();
    int sn = 0;
    while (tt--) {
        string s = in.readString(1, 3e5, "01");
        in.readEoln();
        int n = (int) s.size();
        sn += n;
        reverse(s.begin(), s.end());
        map<pair<int, int>, int> dp;
        dp[make_pair(-1, 0)] = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                continue;
            }
            map<pair<int, int>, int> new_dp;
            for (auto p : dp) {
                for (int j = max(i - 3, p.first.first + 1); j <= min(i + 3, n - 1); j++) {
                    int d = 2 - j % 2;
                    auto k = make_pair(j, (p.first.second + d) % 3);
                    if (!new_dp.count(k)) {
                        new_dp[k] = 100;
                    }
                    new_dp[k] = min(new_dp[k], p.second + abs(i - j));
                }
            }
            swap(dp, new_dp);
        }
        int ans = 100;
        for (auto p : dp) {
            if (p.first.second == 0) {
                ans = min(ans, p.second);
            }
        }
        if (ans == 100) {
            ans = -1;
        }
        cout << ans << '\n';
    }
    assert(sn <= 3e5);
    in.readEof();
    return 0;
}

*/