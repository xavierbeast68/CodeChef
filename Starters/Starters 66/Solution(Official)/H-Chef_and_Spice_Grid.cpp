/*
* Author: Varun Vaddiraju
* Testers: Hriday, Utkarsh Gupta
* Editorialist: Nishank Suresh
*/

//* Setter's Code->
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n, m, k, x, y;
        int v = 0;

        cin >> n >> m >> k;

        for (x = 0; x*x <= k && x < n; x++)
        {
            if ((k-m*x)%(n-x) == 0)
            {
                y = (k-m*x)/(n-x);
                if (y >= 0 && y < m && m*x + n*y - x*y == k)
                {
                    v = 1;
                }
            }
        }

        for (y = 0; y*y <= k && y < m; y++)
        {
            if ((k-n*y)%(m-y) == 0)
            {
                x = (k-n*y)/(m-y);
                if (x >= 0 && x < n && m*x + n*y - x*y == k)
                {
                    v = 1;
                }
            }
        }
        
        if (n*m == k)
        {
            v = 1;
        }

        if (v == 1)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}

//* Tester's Code->
/*

// the_hyp0cr1t3
// 22.11.2022 20:41:56

#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

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

int main() {
#if __cplusplus > 201703L
    namespace R = ranges;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int64_t sum_k = 0, sum_sqrtk = 0, sum_min_nm = 0;

    int tests = readIntLn(1, 2000);
    while(tests--) [&] {
        int n = readIntSp(3, 1'000'000'000);
        int m = readIntSp(3, 1'000'000'000);
        int k = readIntLn(0, 1'000'000'000);
        sum_min_nm += min(n, m);
        sum_k += k;

        bool can = false;
        can |= k % m == 0 and k / m <= n;
        can |= k % n == 0 and k / n <= m;

        if(n > m) {
            for(int a = 1; !can and a < m and k >= a * n; a++)
                can = (k - a * n) % (m - a) == 0
                        and (k - a * n) / (m - a) <= n;
        } else {
            for(int b = 1; !can and b < n and k >= b * m; b++)
                can = (k - b * m) % (n - b) == 0
                    and (k - b * m) / (n - b) <= m;
        }

        cout << (can ? "yEs" : "nO") << '\n';
    }();

    cerr << "sum k = " << sum_k << '\n';
    cerr << "sum sqrt k = " << sum_sqrtk << '\n';
    cerr << "sum min(n, m) = " << sum_min_nm << '\n';

#ifndef W
    readEOF();
#endif

} // ~W

*/

//* Editorialist's Python Code->
/*

def check(n, m, k):
	x = 0
	while x <= n and x*x <= k:
		rem = k - x*m
		if rem < 0: break
		if x == n:
			if rem == 0: return True
		else:
			y = rem // (n - x)
			if y <= m and y*(n - x) == rem: return True
		x += 1
	return False

for _ in range(int(input())):
	n, m, k = map(int, input().split())
	print('Yes' if check(n, m, k) or check(m, n, k) else 'No')

*/