//* Tester's code->

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
    int tt = in.readInt(1, 1e5);
    in.readEoln();
    int sn = 0;
    while (tt--) {
        string s = in.readString(1, 3e5, "01");
        in.readEoln();
        int n = (int) s.size();
        sn += n;
        vector<long long> a(n);
        long long t = 0;
        for (int i = 0; i < n; i++) {
            long long c1 = (n - i) * 1LL * (i + 1);
            if (s[i] == '0') {
                a[i] = c1;
            } else {
                t += c1;
                a[i] = -c1;
            }
        }
        vector<long long> pref(n + 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }
        long long mn = 0;
        long long ans = t;
        for (int i = 0; i < n + 1; i++) {
            mn = min(mn, pref[i]);
            ans = max(ans, t + pref[i] - mn);
        }
        cout << ans << '\n';
    }
    assert(sn <= 3e5);
    in.readEof();
    return 0;
}

// Editorialist's python code->
/*

for _ in range(int(input())):
	s = input()
	ans = mx = cur = 0
	for i in range(len(s)):
		subarrays = (i+1) * (len(s)-i)
		if s[i] == '1':
			ans += subarrays
			subarrays *= -1
		cur += subarrays
		cur = max(cur, 0)
		mx = max(mx, cur)
	print(ans + mx)

*/