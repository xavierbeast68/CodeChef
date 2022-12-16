/*
Authors: utkarsh_25dec
Testers: iceknight1093, mexomerf
Editorialist: iceknight1093
*/

//$ URL-> https://www.codechef.com/problems/DIVBYTHREE
/*
> Difficulty Rating :
% 2650 
*/

//* Setter's Code->

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
    int n=readInt(4,100000,'\n');
    sumN+=n;
    assert(sumN<=200000);
    int A[n+1];
    int one=0,two=0;
    for(int i=1;i<=n;i++)
    {
        if(i==n)
            A[i]=readInt(1,100000,'\n');
        else
            A[i]=readInt(1,100000,' ');
        A[i]%=3;
        if(A[i]==1)
            one++;
        else if(A[i]==2)
            two++;
    }
    int ans=0;
    if(one>two)
        swap(one,two);
    if(one==0 && two==0)
    {
        cout<<0<<'\n';
        return;
    }
    if(one+two == n)
    {
        one--;
        two--;
        ans++;
    }
    if(one==0 && two==1)
    {
        ans+=2;
        two=3;
    }
    else if(one==0 && two==2)
    {
        ans++;
        two=3;
    }
    int diff=abs(one-two);
    while(true)
    {
        if(diff<=2)
            break;
        ans++;
        diff-=4;
    }
    diff=abs(diff);
    ans+=diff;
    int cnt=one+two+diff;
    ans+=(cnt/2);
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
    int T=readInt(1,1000,'\n');
    while(T--)
        solve();
    assert(getchar()==-1);
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}


//* Tester's Code->
/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int ans = 0;
    int a[3] = {}, temp;
    for (int i = 0; i < n; i++)
    {
      cin >> temp;
      temp %= 3;
      a[temp]++;
    }
    if (a[1] > a[2])
    {
      swap(a[1], a[2]);
    }
    while (abs(a[2] - a[1]) > 2)
    {
      a[1] += 2;
      a[2] -= 2;
      ans++;
    }
    if (a[1] > a[2])
    {
      swap(a[1], a[2]);
    }
    if (a[1])
    {
      a[0] += 2 * (a[1] - 1);
      a[2] -= a[1] - 1;
      ans += a[1] - 1;
      a[1] = 1;
      while(a[2] > a[1] && a[0] > 0){
        a[1]++;
        a[0]--;
        ans++;
      }
      a[0] += 2 * (a[1] - 1);
      a[2] -= a[1] - 1;
      ans += a[1] - 1;
      a[1] = 1;
      while(a[2] > a[1] && a[0] > 0){
        a[1]++;
        a[0]--;
        ans++;
      }
      ans += a[1];
      a[0] += 2 * a[1];
      a[2] -= a[1];
      a[1] = 0;
    }
    if (a[2])
    {
      ans += 7 - a[2];
    }
    cout << ans << "\n";
  }
  return 0;
}
*/

//* Editorialist's Python Code->
/*
for _ in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	for i in range(n): a[i] %= 3
	
	x, y = a.count(1), a.count(2)
	x, y = min(x, y), max(x, y)

	ans = 0
	while y >= x + 3:
		ans += 1
		x += 2
		y -= 2
	x, y = min(x, y), max(x, y)
	if y == x+1:
		if x > 0: ans += 2
		else: ans += 6
	if y == x+2:
		if x > 1 or (x > 0 and x+y < n): ans += 4
		else: ans += 5
	print(ans + x)
*/