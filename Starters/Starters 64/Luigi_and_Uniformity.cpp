/**
 * CODER=> xavierbeast68
 * Problem : Luigi and Uniformity (Codechef Starters 64)
 * Date : 09-11-2022
 * URL : https://www.codechef.com/START64C/problems/DIVIDEMAKEEQ
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */


#include <bits/stdc++.h>
using namespace std;
#define endl                    '\n'
#define cendl                   cout<<endl
#define read(x)                 int x; cin >> x;
#define readl(y)                long long y; cin>>y;
#define fastio                  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


/*--Aliases--*/
#define int                     long long
using ll                        = long long;
using ull                       = unsigned long long;
using ld                        = long double;
#define vi                      vector<int>
#define vll                     vector<ll>
#define pii                     pair<ll,ll>
#define ump                     unordered_map
#define pq_max                  priority_queue<ll>
#define pq_min                  priority_queue<ll,vi,greater<ll>>

/*--Constants--*/
constexpr ll INF                = 2e18;
constexpr ld EPS                = 1e-9;
constexpr ll MOD                = 1e9 + 7; //1000000007
constexpr ll mod1               = 998244353;
constexpr ld PI                 = 3.14159265358979323846;


/*--Loop Macros--*/
#define FOR(i,a,b)              for(int i = a; i < b; ++i)
#define FORL(i,a,b)             for(int i = a; i <= b; ++i)
#define FORR(i,a,b)             for(int i = a; i >= b; --i)
#define rep(i , var)            for(auto i : var)
/*--Vector Macros--*/
#define pb                      push_back
#define eb                      emplace_back
#define ppb                     pop_back
/*--other macros--*/
#define sz(x)                   ((int)(x).size())
#define all(x)                  (begin(x), end(x))
#define allr(x)                 (rbegin(x), rend(x))
#define asc(c)                  c.begin(),c.end()
#define des(c)                  c.begin(),c.end(),greater<int>()
#define ff                      first
#define ss                      second
#define mp(x,y)                 make_pair(x,y)
#define sumOf(c)                accumulate(c.begin(),c.end(),0)
#define maxOf(c)                *max_element(c.begin(),c.end())
#define minOf(c)                *min_element(c.begin(),c.end())
#define getUp(su)               transform(su.begin(), su.end(), su.begin(), ::toupper);
#define getDown(su)             transform(su.begin(), su.end(), su.begin(), ::tolower);
#define lb(bin, x)              lower_bound(bin.begin(), bin.end(), x) - bin.begin();
#define ub(bin, x)              upper_bound(bin.begin(), bin.end(), x) - bin.begin();


/*--Operation on bits--*/
/*
#define lshift(x)               (x<<=1)     // x*2
#define rshift(x)               (x>>=1)     // x/2
#define odd(x)                  (x & 1)     // true if x%2==1
#define setbit(num,pos)         (num |= (1 << pos))     // set a bit at 'pos' position in the number ???num'
#define unsetbit(num,pos)       (num &= (~(1 << pos)))  // unset a bit at 'pos' position in the number ???num'
#define togglebit(num,pos)      (num ^= (1 << pos))     // turn bit ???on'(1) if it was ???off'(0)
#define invert(num)             (~num)  // Inverting every bit of num/1???s complement. Add 1 for 2's complement
*/

/*--Print Functions--*/
//std outputs
#define print(x)                (cout<<(x))
#define println(x)              (cout<<(x)<<endl)

/*--Debug--*/
#ifndef ONLINE_JUDGE
#define debug(x)                (cerr <<"<==Testing(#"<<x<<")==>"<< endl)
#else
#define debug(x)
#endif


/*--Debugger--*/
/*
// std errors
void _print(ll t) { cerr << t; }
void _print(ull t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ld t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(string t) { cerr << t; }

//--Debug--
//#define debugO(i) (cout<<"(#"<<i<<")"<<endl)
#ifndef ONLINE_JUDGE
#define debug(x)                cerr <<"(#"; _print(x); cerr <<")"<< endl;
#else
#define debug(x)
#endif
//--Debug File(Debug stderr statements to a file)
void debugf()
{
#ifndef ONLINE_JUDGE
    freopen("debug.txt", "w", stderr);
#endif
}
*/


/*--InputOutputError_From/To_File*/
void file_io()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);
#endif
}


/*--Execution Time--*/
void execTime() {cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;}


/*----------------------------------------Functions----------------------------------------*/

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll max(ll a, ll b) {return a > b ? a : b;}
ll min(ll a, ll b) {return a < b ? a : b;}
ll countDigit(ll n) {return (floor(log10(n) + 1));}
ll log_a_to_base_b(ll a, ll b) {return log2(a) / log2(b);}
ll isPowerof2(ll x) {return (x && !(x & x - 1));} // Checking if given 64 bit integer is power of 2
bool is_whole(ll a) {return (a - floor(a) < 1e-9);} // floor(a)==ceil(a)

ll mod(ll x) { return ((x % MOD + MOD) % MOD);}
// ll addMOD(ll a, ll b) { return (mod(a)+mod(b));}
// ll mul(ll a, ll b) { return (mod(a)*mod(b));}

bool isprime(ll n)
{
    if (n == 1)
    {
        return false;
    }
    if (n % 2 == 0 && n > 2)
    {
        return false;
    }
    if (n % 3 == 0 && n > 3)
    {
        return false;
    }
    for (int i = 5 ; i * i <= n ; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

ll power(ll a , ll b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }
    if (b % 2 == 0)
    {
        return power((a * a) % MOD, b / 2);
    }
    if (b % 2 == 1)
    {
        return (a * power((a * a) % MOD, b / 2)) % MOD;
    }
}

/*-----------------------------------Template Classes-----------------------------------*/

template <class T>
vector<T> readvector(T n)
{
    vector<T> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    return arr;
}// vector<ll> arr = readvector(n);

template <class T>
void printvector(vector<T> arr, T n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/*-----------------------------------||| Here We Go!!! |||-----------------------------------*/


void solve()
{
    /*--Let's Code--*/
    read(n);
    vector<int> arr(n);
    FOR(i, 0, n)
    {
        read(x);
        arr[i] = x;
    }
    if (arr.size() == 1)
    {
        cout << 0 << endl;
    }
    else
    {
        int gcdval = gcd(arr[0], arr[1]);
        FOR(i, 2, n)
        {
            gcdval = gcd(gcdval, arr[i]);
        }
        int count = 0;
        FOR(i, 0, n)
        {
            if (arr[i] != gcdval)
            {
                count++;
            }
        }
        cout << count << endl;
    }
}

signed main()
{

    fastio;
    //file_io();

    /*t=1: default value for single test case*/
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    //execTime();

    fflush(stdout);

    return 0;
}