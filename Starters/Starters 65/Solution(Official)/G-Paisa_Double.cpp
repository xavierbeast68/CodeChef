//* Setter's Code->
#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <map>
#include<bits/stdc++.h>
#define ll int
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
#define pb push_back
using namespace std;
  
  
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
            assert(l<=x && x<=r);
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
#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x << " : "; _print_(x);cerr << endl;
#else
#define dbg(x)
#endif
void _print_(ll t) {cerr << t;}
// void _print_(int t) {cerr << t;}
void _print_(string t) {cerr << t;}
void _print_(char t) {cerr << t;}
// void _print_(ld t) {cerr << t;}
void _print_(double t) {cerr << t;}
template <class T, class V> void _print_(pair <T, V> p);
template <class T> void _print_(vector <T> v);
template <class T> void _print_(set <T> v);
template <class T, class V> void _print_(map <T, V> v);
template <class T> void _print_(multiset <T> v);
template <class T, class V> void _print_(pair <T, V> p) {cerr << "{"; _print_(p.first); cerr << ","; _print_(p.second); cerr << "}";}
template <class T> void _print_(vector <T> v) {cerr << "[ "; for (T i : v) {_print_(i); cerr << " ";} cerr << "]";}
template <class T> void _print_(set <T> v) {cerr << "[ "; for (T i : v) {_print_(i); cerr << " ";} cerr << "]";}
template <class T> void _print_(multiset <T> v) {cerr << "[ "; for (T i : v) {_print_(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print_(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print_(i); cerr << " ";} cerr << "]";}
unordered_map<ll, string> m;
bool pref(string &s1, string &s2)   // Determines if S1 is a prefix of S2
{
    if(s1.length()>s2.length())
        return 0;
    for(ll i=0; i<s1.length(); i++)
    {
        if(s1[i]!=s2[i])
            return 0;
    }
    return 1;
}
bool canmakebigger(vector<ll> freq, string &s1, string &s2) // Determines if we can append characters in S1 such that it is > S2 Lexicographically
{
    ll curr = 25;
    while(curr>=0 && (freq[curr]==0))
            curr--;
    for(ll i=s1.length(); i<s2.length() && curr>=0; i++)
    {
        if(s2[i]<char(curr+'a'))
            return 1;
        if(s2[i]>char(curr+'a'))
            return 0;
        freq[s2[i]-'a']--;
        while(curr>=0 && (freq[curr]==0))
            curr--;
    }
    if(curr<0)
        return 0;
    return 1;
}
bool canconstruct(string s, string &s1, string &s2, ll start, vector<ll> &freq) // Can we create a string s (initially empty), such that we can make it >s1 and <=s2
{
    map<char,ll> m1;
    for(ll i=0; i<26; i++)
    {
        if(freq[i]>0)
            m1[i+'a'] = freq[i];
    }
    bool check = 0; // If check = 1, we have established that s2>s1 and s2>s irrespective of the characters we append now
    for(ll i=start; i<s1.size() && m1.size()>0; i++)
    {
        if(check)
        {
            char ch = (*--m1.end()).first;  // Last Character Required Only
            if(ch>s1[i])
                return 1;
            if(ch<s1[i])
                return 0;
            if(ch==s1[i])
            {
                s.pb(ch);
                m1[ch]--;
                if(m1[ch]==0)
                    m1.erase(ch);
            }
        }
        else
        {
            if(s1[i]<s2[i])
                check = 1;
            char ch1 = '.', ch2 = '.';
            auto itr = m1.upper_bound(s1[i]);
            if(itr!=m1.end())
                ch2 = (*itr).first;
            if(itr!=m1.begin())
            {
                itr--;
                ch1 = (*itr).first;
            }
            // Ch1 and Ch2 - We only require these 2 characters to check for the condition s>s1 && s<=s2
            if((ch1!='.' && ch1>s1[i] && ch1<=s2[i]) || (ch2!='.' && ch2>s1[i] && ch2<=s2[i]))
                return 1;
            if((ch1!='.' && ch1==s1[i]) || (ch2!='.' && ch2==s1[i]))
            {
                char ch = s1[i];
                s.pb(ch);
                m1[ch]--;
                if(m1[ch]==0)
                    m1.erase(ch);
                continue;
            }
            return 0;
        }
    }
    if(s==s1 && m1.size()>0)
        s.pb((*m1.begin()).first);
    return (s>s1 && s<=s2);
}
void solve(ll &n, string s, vector<ll> freq, ll &k, vector<string> &vect, ll &x)
{
    if(m.find(x)!=m.end())
        return;
    if(x==0)    // Base Case
    {
        if(s <= vect[0])
            m[x] = "Yes";
        else
            m[x] = "No";
    }
    else if(x==k)   // Base Case
    {
        if(s > vect.back())
            m[x] = "Yes";
        else if(pref(s,vect.back()) && canmakebigger(freq,s,vect.back()))   // 4,5,6
            m[x] = "Yes";
        else
            m[x] = "No";
    }
    else
    {
        string prev = vect[x-1], next = vect[x];
        if((prev==next) || (s>next))    // Base Case
        {
            m[x] = "No";
            return;
        }
        if(s > prev)
            m[x] = "Yes";
        else if(s < prev)   
        {
            if(pref(s,prev) && pref(s,next))
            {
                if(canconstruct(s,prev,next,s.size(),freq))
                    m[x] = "Yes";
                else
                    m[x] = "No";
            }
            else if(pref(s,prev))
            {
                if(canmakebigger(freq,s,prev))
                    m[x] = "Yes";
                else
                    m[x] = "No";
            }
            else
                m[x] = "No";
        }
        else
        {
            for(ll i=0; i<26; i++)
            {
                if(freq[i]>0)
                {
                    s.pb(char(i+'a'));
                    break;
                }
            }
            if(s>prev && s<=next)
                m[x] = "Yes";
            else
                m[x] = "No";
        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("15.in", "r", stdin);
        freopen("15.out", "w", stdout);
    #endif
    int N=readIntLn(1,1e4); // Ensures that an integer in the range [1, 3] is inputted, and that there is a New Line (Ln) right after that. This needs Unix-style line endings (ie. \n instead of \r\n). So generate the test files on an Unix machine (eg. Linux, Mac).
    string s = readStringLn(N, N);
    vector<ll> freq(26);
    for(ll i=0; i<26; i++)
    {
        if(i==25)
            freq[i] = readIntLn(0, 1e6);
        else
            freq[i] = readIntSp(0, 1e6);
    }
    int K = readIntLn(1, 1e4);
    vector<string> vect(K);
    int sum1 = 0;
    for(int i=0; i<K; i++)
    {
        vect[i] = readStringLn(1, 1e4);
        sum1+=vect[i].size();
    }
    assert(sum1<=1e5);
    sort(vect.begin(), vect.end());
    for(int i=0; i<=K; i++)
    {
        solve(N, s, freq, K, vect, i);
        cout<<m[i]<<endl;
    }
    assert(getchar()==-1); // Ensures that there are no extra characters at the end.
    cerr<<"SUCCESS\n"; // You should see this on the http://campus.codechef.com/files/stderr/SUBMISSION_ID page, at the bottom.
    timetaken;
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

int main() {
    input_checker in;
    int n = in.readInt(1, 1e4);
    in.readEoln();
    string s = in.readString(n, n, in.lower);
    in.readEoln();
    vector<int> f(26);
    for (int i = 0; i < 26; i++) {
        f[i] = in.readInt(0, 1e6);
        (i == 25 ? in.readEoln() : in.readSpace());
    }
    int k = in.readInt(1, 1e4);
    in.readEoln();
    int ss = 0;
    vector<string> p(k);
    for (int i = 0; i < k; i++) {
        p[i] = in.readString(1, 1e4, in.lower);
        ss += (int) p[i].size();
        in.readEoln();
    }
    sort(p.begin(), p.end());
    assert(ss <= 1e5);
    vector<string> ans(k + 1, "No");
    if (s <= p[0]) {
        ans[0] = "Yes";
    }
    p.emplace_back("{");
    for (int i = 1; i <= k; i++) {
        if (s > p[i]) {
            continue;
        }
        // s <= p[i]
        if (p[i - 1] == p[i]) {
            continue;
        }
        // p[i - 1] < p[i]
        if (p[i - 1] < s) {
            ans[i] = "Yes";
            continue;
        }
        // s <= p[i - 1] < p[i]
        if (s.size() > p[i - 1].size()) {
            continue;
        }
        // s + "zzz..." > p[i - 1]
        if (p[i - 1].substr(0, s.size()) != s) {
            continue;
        }
        // prefix of p[i - 1] == s
        ans[i] = "Yes";
        int big = 1;
        if ((int) p[i].size() >= n && p[i].substr(0, n) == s) {
            big = 0;
        }
        auto g = f;
        for (int j = n; j <= (int) max(p[i - 1].size(), p[i].size()); j++) {
            int c = -1;
            if (j < (int) p[i - 1].size()) {
                c = p[i - 1][j] - 'a';
            }
            int d = 25;
            if (!big) {
                if (j >= (int) p[i].size()) {
                    ans[i] = "No";
                    break;
                }
                d = p[i][j] - 'a';
            }
            int t = 0;
            for (int l = d; l >= max(0, c); l--) {
                if (g[l]) {
                    if (l > c) {
                        t = 2;
                    } else {
                        t = 1;
                    }
                    break;
                }
            }
            if (t == 0) {
                ans[i] = "No";
                break;
            }
            if (t == 2) {
                break;
            }
            g[c]--;
            if (c < d) {
                big = 1;
            }
        }
    }
    for (int i = 0; i <= k; i++) {
        cout << ans[i] << " \n"[i == k];
    }
    in.readEof();
    return 0;
}

*/

//* Editorialist's Python Code->
/*

n = int(input())
s = input()
have = list(map(int, input().split()))
k = int(input())
strings = []
for i in range(k):
	strings.append(input())
strings.sort()
strings.append((len(strings[-1])+5)*'z')

print('Yes' if s <= strings[0] else 'No')

for i in range(k):
	if strings[i] == strings[i+1] or s > strings[i+1]:
		print('No')
		continue
	if s > strings[i]:
		print('Yes')
		continue
	if len(strings[i]) < n or strings[i][:n] != s:
		print('No')
		continue
	used = [0 for _ in range(26)]
	ans = 'Yes'
	ispref = strings[i+1][:n] == s
	for pos in range(n, 200000):
		hi = 0
		if ispref == True: hi = ord(strings[i+1][pos]) - ord('a') + 1
		else: hi = 26
		
		if pos == len(strings[i]):
			ans = 'No'
			for c in range(hi):
				if used[c] < have[c]:
					ans = 'Yes'
					break
			break
		
		lo = ord(strings[i][pos]) - ord('a') + 1
		ans = 'No'
		for c in range(lo, hi):
			if used[c] < have[c]:
				ans = 'Yes'
				break
		if ans == 'Yes': break
		if used[lo-1] < have[lo-1]:
			used[lo-1] += 1
			if ispref == True and strings[i][pos] != strings[i+1][pos]: ispref = False
			ans = 'Yes'
			continue
		ans = 'No'
		break
	print(ans)

*/