//$ URL-> https://www.codechef.com/problems/BSSORT
//! Pre-requisite->
//^ Binary Search or Two-pointers

/*
* Author: Jeevan Jyot Singh
* Testers: Hriday, Utkarsh Gupta
* Editorialist: Nishank Suresh
*/

//* Setter's Code (C++, Binary Search)->
#ifdef WTSH
    #include <wtsh.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
    #define dbg(...)
#endif

#define int long long
#define endl "\n"
#define sz(w) (int)(w.size())
using pii = pair<int, int>;

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

int sumN = 0;

void solve()
{
    int n = readIntLn(1, 1e5);
    sumN += n;
    string s = readStringLn(n, n);
    assert(*max_element(s.begin(), s.end()) <= '1');
    assert(*min_element(s.begin(), s.end()) >= '0');
    array<vector<int>, 2> occ{}; 
    for(int i = 0; i < n; i++)
        occ[s[i] - '0'].push_back(i);
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int cur = i - 1;
        for(int x: {1, 1, 0, 0})
        {
            auto it = upper_bound(occ[x].begin(), occ[x].end(), cur);
            if(it == occ[x].end())
            {
                cur = n;
                break;
            } 
            cur = *it;
        }
        ans += cur - i;
    }
    cout << ans << endl;
}

int32_t main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int T = readIntLn(1, 1e5);
    for(int tc = 1; tc <= T; tc++)
    {
        solve();
    }
    readEOF();
    assert(sumN <= 5e5);
    return 0;
}

//* Tester's Code (C++, binary search)->
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
    assert(sumN<=500000);
    string s=readString(n,n,'\n');
    for(auto ch:s)
        assert(ch=='0' || ch=='1');
    int nextone[n+2];
    int prevzero[n+2];
    s='$'+s;
    for(int i=0;i<=n+1;i++)
    {
        nextone[i]=n+1;
        prevzero[i]=0;
    }
    for(int i=n;i>=1;i--)
    {
        if(s[i]=='1')
            nextone[i]=i;
        else
            nextone[i]=nextone[i+1];
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='0')
            prevzero[i]=i;
        else
            prevzero[i]=prevzero[i-1];
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        int l=i,r=n;
        while(l<=r)
        {
            int mid=(l+r)/2;
            int a=nextone[i];
            int b=((a==n+1) ? n+1 : nextone[a+1]);
            int c=prevzero[mid];
            int d=(c==0 ? 0 : prevzero[c-1]);
            if(d>b)
                r=mid-1;
            else
                l=mid+1;
        }
        ans+=(r-i+1);
    }
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

//* Editorialist's Python Code (Python, 2-pointers)->
/*

for _ in range(int(input())):
    n = int(input())
    s = input()
    ans = 0
    p1 = p2 = p3 = p4 = n
    for i in reversed(range(n)):
        if s[i] == '1':
            zeros = []
            for j in range(p1, p2):
                if s[j] == '0': zeros.append(j)
            if len(zeros) > 1:
                p3 = zeros[0]
                p4 = zeros[1]
            elif len(zeros) == 1:
                p4 = p3
                p3 = zeros[0]
            p2 = p1
            p1 = i
        ans += p4 - i
    print(ans)

*/