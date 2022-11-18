//! Pre-requisites->
//* Prefix Sums=>
//* https://usaco.guide/silver/prefix-sums?lang=cpp


//* Setter's Code->
//	Code by Sahil Tiwari (still_me)

#include<bits/stdc++.h>
#define still_me main
#define endl "\n"
#define int long long int
#define all(a) (a).begin() , (a).end()
#define print(a) for(auto TEMPORARY: a) cout<<TEMPORARY<<" ";cout<<endl;
#define tt int TESTCASE;cin>>TESTCASE;while(TESTCASE--)
#define arrin(a,n) for(int INPUT=0;INPUT<n;INPUT++)cin>>a[INPUT]

using namespace std;
const int mod = 1e9+7;
const int inf = 1e18;

void solve() {
    int n , q;
    cin>>n>>q;
    vector<int> a(n);
    arrin(a , n);
    vector<vector<int>> b(n+1 , vector<int>(61));
    for(int i=0;i<n;i++) {
        for(int j=0;j<61;j++) {
            if(a[i] & (1ll << j))
                b[i+1][j]++;
            b[i+1][j] += b[i][j];
        }
    }
    while(q--) {
        int k , l , r , x , y;
        cin>>k>>l>>r>>x>>y;
        int o1 = b[r][k] - b[l-1][k];
        int o2 = b[y][k] - b[x-1][k];
        int z1 = r-l+1 - o1;
        int z2 = y-x+1 - o2;
        cout<<(o1*z2 + o2*z1)<<endl;
    }

}

signed still_me()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    tt{
        solve();
    }
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
int sumN=0,sumQ=0;
void solve()
{
    int n=readInt(1,100000,' ');
    sumN+=n;
    int q=readInt(1,500000,'\n');
    sumQ+=q;
    assert(sumN<=100000);
    assert(sumQ<=500000);
    int sum[n+1][65];
    memset(sum,0,sizeof(sum));
    long long A[n+1];
    memset(A,0,sizeof(A));
    for(int i=1;i<=n;i++)
    {
        if(i==n)
            A[i]=readInt(0,1LL<<60,'\n');
        else
            A[i]=readInt(0,1LL<<60,' ');
        for(int j=0;j<60;j++)
        {
            sum[i][j]=sum[i-1][j];
            if((A[i]&(1LL<<j))!=0)
                sum[i][j]++;
        }
    }
    while(q--)
    {
        int k=readInt(0,59,' ');
        int l1=readInt(1,n,' ');
        int r1=readInt(l1,n,' ');
        int l2=readInt(r1+1,n,' ');
        int r2=readInt(l2,n,'\n');
        long long left1s=sum[r1][k]-sum[l1-1][k];
        long long left0s=(r1-l1+1)-left1s;
        long long right1s=sum[r2][k]-sum[l2-1][k];
        long long right0s=(r2-l2+1)-right1s;
        cout<<(left1s*right0s)+(left0s*right1s)<<'\n';
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
    int T=readInt(1,50000,'\n');
    while(T--)
        solve();
    assert(getchar()==-1);
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

*/


//* Edititorialist's Python Code->
/*

for _ in range(int(input())):
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    pref = [[0 for i in range(60)] for _ in range(n+1)]
    for i in range(n):
        for k in range(60):
            pref[i+1][k] = pref[i][k] + ((a[i] >> k) & 1)
    for i in range(q):
        k, l1, r1, l2, r2 = map(int, input().split())
        on1, on2 = pref[r1][k] - pref[l1-1][k], pref[r2][k] - pref[l2-1][k]
        off1, off2 = r1-l1+1 - on1, r2-l2+1 - on2
        print(on1*off2 + on2*off1)

*/