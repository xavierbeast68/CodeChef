//! https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/#:~:text=The%20Longest%20Increasing%20Subsequence%20(LIS)%20problem%20is%20to%20find%20the,50%2C%2060%2C%2080%7D.
//* https://www.geeksforgeeks.org/counting-frequencies-of-array-elements/

/**
 * @author xavierbeast68
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 * Problem- Minimise LCS (Codechef Starters- 61)
 * Link- https://www.codechef.com/submit/MINLCS?tab=statement
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
	string a, b; cin >> a >> b;
	unordered_map<char, int> mp1;
	unordered_map<char, int> mp2;

	for (int i = 0; i < n; i++) {mp1[a[i]]++;}
	for (int i = 0; i < n; i++) {mp2[b[i]]++;}

	int c = 0;
	for (auto i : mp1)  // i is iterator to mp1
	{
		auto it = mp2.find(i.first);  // i.first is key of mp1
		if (it != mp2.end())
		{
			int minm = min(i.second, (*(it)).second);  // i.second is value of mp1 and (*it).second is value of mp2
			if (minm > c)
			{
				c = minm;
			}
		}
	}
	println(c);
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


/** Editors Solution->

#include<bits/stdc++.h>
using namespace std;

void solution()
{
	int n;
	string a,b;
	cin >> n >> a >> b;

	// creating maps to store frequency of each character in strings;
	map<char,int> freqa, freqb;

	// running foreach loops->
	for(char c: a) freqa[c]++;
	for(char c: b) freqb[c]++;

	int ans=0;
	for(auto entry: freqa) // entry-> points to the keys of map freqa
	{
		char c=entry.first; // char c stores the character(key at pointer entry
		int cnt=entry.second; // int cnt stores the value part of the key-value pairs.
		ans=max(ans,min(cnt,freqb[c]));
	}
	cout<<ans<<'\n';
}

int main()
{
	int T;
	cin>>T;
	while(T--) solution();
	return 0;
}


//Python Code->
import collections
for _ in range(int(input())):
	n = int(input())
	a = input()
	b = input()
	d1, d2 = collections.Counter(a), collections.Counter(b)
	ans = 0
	for c in 'qwertyuiopasdfghjklzxcvbnm':
		if c not in d1 or c not in d2: continue
		ans = max(ans, min(d1[c], d2[c]))
	print(ans)
*/

