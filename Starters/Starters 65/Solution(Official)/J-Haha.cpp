//* Setter's code (C++)->

//	Code by Sahil Tiwari (still_me)

#include<bits/stdc++.h>
#define still_me main
#define tt int TESTCASE;cin>>TESTCASE;while(TESTCASE--)

using namespace std;

void chal() {
    int n;
    cin>>n;
    cout<<min(4 , (n+1)/2)<<endl;
    vector<int> a(n+1);
    if(n < 8) {
        // cout<<(n+1)/2<<endl;
        for(int i=1;i<=n;i++) {
            a[i] = (i+1)/2;
        }
        if(n == 5) {
            swap(a[3] , a[5]);
            a[4] = a[3];
        }
    }
    else {
        // cout<<4<<endl;
        if(n % 4 == 0 || n % 4 == 3) {
            for(int i=1;i<=n;i++) {
                a[i] = (i % 4);
                if(!a[i])
                    a[i] = 4;
            }
        }
        else {
            for(int i=1;i<=n;i++) {
                if(i % 4 == 1) {
                    a[i] = 4;
                }
                else if(i % 4) {
                    a[i] = i % 4;
                }
                else {
                    a[i] = 1;
                }
            }
        }
    }

    
    set<pair<int,int>> b;
    for(int i=1;i<=n;i++) {
        b.insert({a[i] , i});
    }
    set<pair<int,int>> edges;
    while(!b.empty()) {
        pair<int,int> x = *b.begin();
        b.erase(x);
        pair<int,int> y;
        vector<pair<int,int>> c;
        while(x.first) {
            x.first--;
            y = *b.rbegin();
            // cout<<b.size()<<endl;
            b.erase(y);
            c.push_back(y);
            edges.insert({x.second , y.second});
            // cout<<x.second<<" "<<y.second<<endl;
        }
        for(auto i: c) {
            b.insert({i.first-1 , i.second});
        }
    }
    cout<<edges.size()<<"\n";
    for(auto i: edges) {
        cout<<i.first<<" "<<i.second<<"\n";
    }
    // cout<<"done\n";
}

signed still_me()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    tt{
        chal();
    }
    // cout<<"done\n";
    return 0;
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
    int n=readInt(1,100000,'\n');
    sumN+=n;
    assert(sumN<=100000);
    vector <pair<int,int>> edges;
    if(n>=8)
    {
        cout<<4<<'\n';
        if(n%4==0)
        {
            vector <int> ones,twos,threes,fours;
            for(int i=1;i<=n;i++)
            {
                if((i%4)==1)
                    ones.pb(i);
                if((i%4)==2)
                    twos.pb(i);
                if((i%4)==3)
                    threes.pb(i);
                if((i%4)==0)
                    fours.pb(i);
            }
            for(int i=0;i<threes.size()-1;i++)
                edges.pb(mp(threes[i],threes[i+1]));
            edges.pb(mp(threes[threes.size()-1],twos[0]));
            edges.pb(mp(threes[0],twos[0]));
            for(int i=0;i<fours.size()-1;i++)
                edges.pb(mp(fours[i],fours[i+1]));
            edges.pb(mp(fours[fours.size()-1],twos[1]));
            for(int i=1;i<twos.size()-1;i++)
                edges.pb(mp(twos[i],twos[i+1]));
            edges.pb(mp(fours[0],twos[twos.size()-1]));
            for(int i=0;i<fours.size();i++)
            {
                edges.pb(mp(ones[i],fours[i]));
                edges.pb(mp(threes[i],fours[i]));
            }
        }
        else if(n%4==1)
        {
            vector <int> ones,twos,threes,fours;
            for(int i=1;i<=n;i++)
            {
                if((i%4)==1)
                    twos.pb(i);
                if((i%4)==2)
                    ones.pb(i);
                if((i%4)==3)
                    threes.pb(i);
                if((i%4)==0)
                    fours.pb(i);
            }
            for(int i=0;i<threes.size()-1;i++)
                edges.pb(mp(threes[i],threes[i+1]));
            edges.pb(mp(threes[threes.size()-1],twos[0]));
            edges.pb(mp(threes[0],twos[0]));
            for(int i=0;i<fours.size()-1;i++)
                edges.pb(mp(fours[i],fours[i+1]));
            edges.pb(mp(fours[fours.size()-1],twos[1]));
            for(int i=1;i<twos.size()-1;i++)
                edges.pb(mp(twos[i],twos[i+1]));
            edges.pb(mp(fours[0],twos[twos.size()-1]));
            for(int i=0;i<fours.size();i++)
            {
                edges.pb(mp(ones[i],fours[i]));
                edges.pb(mp(threes[i],fours[i]));
            }
        }
        else if(n%4==2)
        {
            vector <int> ones,twos,threes,fours;
            for(int i=1;i<=n;i++)
            {
                if((i%4)==1)
                    ones.pb(i);
                if((i%4)==2)
                    threes.pb(i);
                if((i%4)==3)
                    twos.pb(i);
                if((i%4)==0)
                    fours.pb(i);
            }
            for(int i=0;i<threes.size()-1;i++)
                edges.pb(mp(threes[i],threes[i+1]));
            edges.pb(mp(threes[threes.size()-1],twos[0]));
            edges.pb(mp(threes[0],twos[0]));
            for(int i=0;i<fours.size()-1;i++)
                edges.pb(mp(fours[i],fours[i+1]));
            edges.pb(mp(fours[fours.size()-1],twos[1]));
            for(int i=1;i<twos.size()-1;i++)
                edges.pb(mp(twos[i],twos[i+1]));
            edges.pb(mp(fours[0],twos[twos.size()-1]));
            for(int i=0;i<fours.size();i++)
            {
                edges.pb(mp(ones[i],fours[i]));
                edges.pb(mp(threes[i],fours[i]));
            }
            edges.pb(mp(ones[ones.size()-1],threes[threes.size()-1]));
        }
        else
        {
            vector <int> ones,twos,threes,fours;
            for(int i=1;i<=n;i++)
            {
                if((i%4)==1)
                    ones.pb(i);
                if((i%4)==2)
                    twos.pb(i);
                if((i%4)==3)
                    threes.pb(i);
                if((i%4)==0)
                    fours.pb(i);
            }
            for(int i=0;i<threes.size()-1;i++)
                edges.pb(mp(threes[i],threes[i+1]));
            edges.pb(mp(threes[threes.size()-1],twos[0]));
            edges.pb(mp(threes[0],twos[0]));
            for(int i=0;i<fours.size()-1;i++)
                edges.pb(mp(fours[i],fours[i+1]));
            edges.pb(mp(fours[fours.size()-1],twos[1]));
            for(int i=1;i<twos.size()-1;i++)
                edges.pb(mp(twos[i],twos[i+1]));
            edges.pb(mp(fours[0],twos[twos.size()-1]));
            for(int i=0;i<fours.size();i++)
            {
                edges.pb(mp(ones[i],fours[i]));
                edges.pb(mp(threes[i],fours[i]));
            }
            edges.pb(mp(ones[ones.size()-1],threes[threes.size()-1]));
        }
    }
    else
    {
        if(n==2)
        {
            cout<<1<<'\n';
            edges.pb(mp(1,2));
        }
        if(n==3)
        {
            cout<<2<<'\n';
            edges.pb(mp(1,3));
            edges.pb(mp(3,2));
        }
        if(n==4)
        {
            cout<<2<<'\n';
            edges.pb(mp(1,3));
            edges.pb(mp(3,4));
            edges.pb(mp(4,2));
        }
        if(n==5)
        {
            cout<<3<<'\n';
            edges.pb(mp(3,4));
            edges.pb(mp(4,5));
            edges.pb(mp(5,3));
            edges.pb(mp(5,1));
            edges.pb(mp(4,2));
        }
        if(n==6)
        {
            cout<<3<<'\n';
            edges.pb(mp(3,4));
            edges.pb(mp(4,6));
            edges.pb(mp(6,5));
            edges.pb(mp(5,3));
            edges.pb(mp(5,1));
            edges.pb(mp(6,2));
        }
        if(n==7)
        {
            cout<<4<<'\n';
            edges.pb(mp(3,4));
            edges.pb(mp(4,6));
            edges.pb(mp(6,7));
            edges.pb(mp(7,5));
            edges.pb(mp(5,3));
            edges.pb(mp(7,1));
            edges.pb(mp(7,2));
            edges.pb(mp(5,6));
        }
    }
    cout<<edges.size()<<'\n';
    for(auto it:edges)
        cout<<it.first<<' '<<it.second<<'\n';
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int T=readInt(1,10000,'\n');
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
    int tt = in.readInt(1, 1e4);
    in.readEoln();
    int sn = 0;
    while (tt--) {
        int n = in.readInt(2, 1e5);
        in.readEoln();
        if (n >= 7) {
            vector<pair<int, int>> e;
            vector<int> t;
            if (n % 4 == 0) {
                for (int i = 0; i < n; i += 4) {
                    e.emplace_back(i, i + 3);
                    e.emplace_back(i + 1, i + 2);
                    e.emplace_back(i + 1, i + 3);
                    t.emplace_back(i + 2);
                    t.emplace_back(i + 3);
                }
            } else if (n % 4 == 1) {
                for (int i = 0; i < n; i += 4) {
                    if (i + 4 <= n) {
                        e.emplace_back(i + 1, i + 3);
                        e.emplace_back(i, i + 2);
                        e.emplace_back(i, i + 3);
                        t.emplace_back(i + 2);
                        t.emplace_back(i + 3);
                    } else {
                        t.emplace_back(i);
                    }
                }
            } else if (n % 4 == 2) {
                for (int i = 0; i < n; i += 4) {
                    if (i + 4 <= n) {
                        e.emplace_back(i, i + 3);
                        e.emplace_back(i + 1, i + 2);
                        e.emplace_back(i + 2, i + 3);
                        t.emplace_back(i + 1);
                        t.emplace_back(i + 3);
                    } else {
                        e.emplace_back(i, i + 1);
                        t.emplace_back(i + 1);
                    }
                }
            } else {
                for (int i = 0; i < n; i += 4) {
                    if (i + 4 <= n) {
                        e.emplace_back(i, i + 3);
                        e.emplace_back(i + 1, i + 2);
                        e.emplace_back(i + 1, i + 3);
                        t.emplace_back(i + 2);
                        t.emplace_back(i + 3);
                    } else {
                        e.emplace_back(i, i + 1);
                        e.emplace_back(i + 1, i + 2);
                        t.emplace_back(i + 2);
                    }
                }
            }
            t.emplace_back(t[0]);
            for (int i = 0; i < (int) t.size() - 1; i++) {
                e.emplace_back(t[i], t[i + 1]);
            }
            cout << 4 << '\n';
            cout << e.size() << '\n';
            for (auto [x, y]: e) {
                cout << x + 1 << " " << y + 1 << '\n';
            }
        } else {
            if (n == 2) {
                cout << "1 1 1 2" << '\n';
            } else if (n == 3) {
                cout << "2 2 1 3 2 3" << '\n';
            } else if (n == 4) {
                cout << "2 3 2 3 3 4 1 4" << '\n';
            } else if (n == 5) {
                cout << "3 5 1 5 2 4 4 5 3 4 3 5" << '\n';
            } else {
                cout << "3 6 1 5 2 6 3 5 3 6 4 5 4 6" << '\n';
            }
        }
    }
    assert(sn <= 1e5);
    in.readEof();
    return 0;
}

*/