//$ URL-> https://www.codechef.com/problems/SPLITPAL
//! Pre-requisite->
//^ Two pointers or deque

/*
* Author: Jeevan Jyot Singh
* Testers: Hriday, Utkarsh Gupta
* Editorialist: Nishank Suresh
*/

//* Setter's Code->
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
    vector<int> a = readVectorInt(n, 1, 1e5);
    int L = 0, R = n - 1, ans = 0;
    while(L < R)
    {
        if(a[L] == a[R])
            L++, R--;
        else if(a[L] < a[R])
            a[R] -= a[L], L++, ans++;
        else
            a[L] -= a[R], R--, ans++;
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
    assert(sumN <= 2e5);
    return 0;
}


//* Editorialist's Code (C++, deque)->
/*

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
	    int n; cin >> n;
	    deque<int> dq;
	    for (int i = 0; i < n; ++i) {
	        int x; cin >> x;
	        dq.push_back(x);
	    }
	    int ans = 0;
	    while (dq.size() > 1) {
	        int x = dq.front(), y = dq.back();
	        dq.pop_front(); dq.pop_back();
	        if (x == y) continue;
	        ++ans;
	        if (x < y) dq.push_back(y-x);
	        else dq.push_front(x-y);
	    }
	    cout << ans << '\n';
	}
	return 0;
}

*/

//* Editorialist's Code (Python, 2-pointers)
/*

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    L, R = 0, n-1
    ans = 0
    while L < R:
        if a[L] == a[R]:
            L += 1
            R -= 1
        elif a[L] < a[R]:
            a[R] -= a[L]
            L += 1
            ans += 1
        else:
            a[L] -= a[R]
            R -= 1
            ans += 1
    print(ans)

*/