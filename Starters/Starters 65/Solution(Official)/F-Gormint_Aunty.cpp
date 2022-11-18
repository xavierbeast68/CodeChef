//* Setter's Code->
//	Code by Sahil Tiwari (still_me)

#include <bits/stdc++.h>
#define still_me main
#define print(a) for(auto TEMPORARY: a) cout<<TEMPORARY<<" ";
#define tt int TESTCASE;cin>>TESTCASE;while(TESTCASE--)

using namespace std;
const int mod = 1e9+7;
const int inf = 1e18;

void solve() {
    int n , k;
    cin>>n>>k;
    int m = n/k;
    int ans = (n+m-1) / m;
    cout<<ans<<endl;
    vector<vector<int>> a(m);
    int c = 1;
    while(n) {
        for(int i=0;i<m && n;i++) {
            a[i].push_back(c);
            n--;
        }
        c++;
    }
    for(auto i: a){
        print(i);
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
        int n = in.readInt(1, 5e5);
        in.readSpace();
        int k = in.readInt(1, n);
        in.readEoln();
        sn += n;
        int x = k;
        while (n / k * x < n) {
            x++;
        }
        cout << x << endl;
        int t = n - n / k * k;
        int c = 0;
        for (int i = 0; i < n; i++) {
            cout << c + 1 << " \n"[i == n - 1];
            if (c >= k) {
                t--;
            }
            c++;
            if (c == x || (c >= k && t == 0)) {
                c = 0;
            }
        }
    }
    assert(sn <= 5e5);
    in.readEof();
    return 0;
}

*/

//* Editorialist's Code->
/*

for _ in range(int(input())):
    n, k = map(int, input().split())
    cols = k + (n%k + n//k - 1)//(n // k)
    print(cols)
    ans = [[i for i in range(1, k+1)] for _ in range(n//k)]
    n -= k * (n // k)
    for col in range(k+1, cols+1):
        for list in ans:
            if n > 0:
                list.append(col)
                n -= 1
    for list in ans:
        print(*list, end = ' ')
    print()

*/