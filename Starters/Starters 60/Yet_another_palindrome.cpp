/**
 * @author xavierbeast68
 * Problem Name- Yet Another Palindrome Problem ( Codechef Starters 60)
 * Problem Link- https://www.codechef.com/submit/ARRPAL
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
/*--Loop Macros--*/
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORL(i,a,b) for(int i = a; i <= b; i++)
#define FORR(i,a,b) for(int i = a; i >= b; i--)
/*--Vector Macros--*/
#define pb push_back
#define ppb pop_back
/*--Print Macros--*/
#define print(x) (cout<<(x))
#define println(x) (cout<<(x)<<endl)

/*----------------------------------------Functions----------------------------------------*/

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll max(ll a, ll b) {return a > b ? a : b;}
ll min(ll a, ll b) {return a < b ? a : b;}
ll countDigit(ll n) {return (floor(log10(n) + 1));}

/*-----------------------------------||| Here We Go!!! |||-----------------------------------*/

void solve()
{
	/*--Let's Code--*/
	int n; cin >> n;
	vector <int> a(n);
	FOR(i, 0, n)
	{
		cin >> a[i];
	}
	if (n == 1)
	{
		println(0);
	}
	/*
	else if (n == 2)
	{
		if (a[0] > a[1])
		{
			println(-1);
		}
		else if (a[0] == a[1])
		{
			println(0);
		}
		else
		{
			println((a[1] - a[0]));
		}
	}
	*/
	else
	{
		vector<int>b;
		int neg = 0;
		FOR(i, 0, n / 2)
		{
			int x = a[n - i - 1] - a[i];
			if (x < 0)
			{
				neg = 1;
				break;
			}
			b.pb(x);
		}
		if (neg == 1)
		{
			println(-1);
		}
		else
		{
			vector<int>c;
			c.insert(c.begin(), b.begin(), b.end());
			sort(c.begin(), c.end(), greater<int>());
			int flag = 0;
			FOR(i, 0, b.size())
			{
				if (b[i] != c[i])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				println(b[0]);
			}
			else
			{
				println(-1);
			}
		}
	}
	/*
	else
	{
		string s1 = "";
		int neg = 0;
		FOR(i, 0, n / 2)
		{
			int x = a[n - i - 1] - a[i];
			if (x < 0)
			{
				neg = 1;
				break;
			}
			string temp = to_string(x);
			s1.append(temp);
		}
		if (neg == 1)
		{
			println(-1);
		}
		else
		{
			string s2 = s1;
			sort(s2.begin(), s2.end(), greater<char>());
			if (s1.compare(s2) == 0)
			{
				println(s1[0]);
			}
			else
			{
				println(-1);
			}
		}
	}
	*/
}

signed main()
{
	fastio;

	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

/*! Problem=>*/

// * Setter's Soln
/*
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
    int n = readIntLn(1, 3e5);
    sumN += n;
    vector<int> a = readVectorInt(n, 1, 1e9);
    vector<int> d;
    for(int i = 0; i <= n / 2 - 1; i++)
        d.push_back(a[n - 1 - i] - a[i]);
    if(*min_element(d.begin(), d.end()) >= 0 and is_sorted(d.rbegin(), d.rend()))
        cout << d[0] << endl;
    else
        cout << -1 << endl;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = readIntLn(1, 1e5);
    for(int tc = 1; tc <= T; tc++)
    {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    assert(sumN <= 3e5);
    readEOF();
    return 0;
}
*/

//* Tester's Soln
/*
int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    int a[n];
	    for(int i = 0; i < n; i++) cin >> a[i];
	    int b[n];
	    memset(b, 0, sizeof(b));
	    for(int i = 0; i < n/2; i++) b[i] = a[n - 1 - i] - a[i];
	    int bad = 0;
	    if(b[0] < 0) bad = 1;
	    for(int i = 1; i < n; i++)
	        if(b[i] > b[i - 1] || b[i] < 0) bad = 1;
	    if(bad) cout << "-1\n";
	    else cout << a[n - 1] - a[0] << "\n";
	}
	return 0;
}
*/
