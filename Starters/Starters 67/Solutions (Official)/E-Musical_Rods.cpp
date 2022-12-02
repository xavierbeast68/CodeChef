//$ URL-> https://www.codechef.com/problems/MUSROD
//! Pre-requisite->
//^ Sorting, exchange arguments

//* Setter's Code->

#include <bits/stdc++.h>
#include <iostream>
#define ull  long long int
#define ll long long int
using namespace std;
#define maxlen 100

bool sortVec(const vector<ull> l, const vector<ull> r){
    if (l[1]*r[0] == l[0]*r[1]) return l[0] < r[0];
	else if (l[1]*r[0] > l[0]*r[1])return false;
	else return true;
}


void solve (ll k){
	ull n;
	cin>>n;
	vector<vector<ull>> rods(n, vector<ull>(2,0));
	ull sum = 0;
	for (ull i = 0; i < n; i++){
		cin>>rods[i][0];
		sum+=rods[i][0];
	}
	for (ull i = 0; i < n; i++){
		cin>>rods[i][1];
	}

	//cout<<"here"<<"\n";
	sort(rods.begin(), rods.end(), sortVec);
	//cout<<"here"<<"\n";
	ull pos = 0;
	ull ans = 0;
	for (ull i = 0; i < n; i++){
        //cout<<pos<<" "<<rods[i][1]<<" "<<ans<<"\n";
		ans += pos*rods[i][1];
		pos += rods[i][0];
	}
	cout<<ans<<"\n";

}

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); 
    int t;
	cin>>t;
	for(int k=1;k<=t;k++){
		solve(k);
	}
	return 0;
}

//* Tester's Code->

/*

#include <bits/stdc++.h>
using namespace std;
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

bool custom(pair<int, int>& a, pair<int, int>& b) {
    return a.first*b.second > a.second*b.first;
}

int main() {
	int t;
	t = readIntLn(1, 1000);
	while(t--) {
	    int n;
	    n = readIntLn(1, 100000);
	    vector<int> a(n), b(n);
	    for(int i = 0; i < n - 1; i++) a[i] = readIntSp(1, 10000);
	    a[n - 1] = readIntLn(1, 10000);
	    for(int i = 0; i < n - 1; i++) b[i] = readIntSp(1, 10000);
	    b[n - 1] = readIntLn(1, 10000);
	    vector<pair<int, int>> v(n);
	    for(int i = 0; i < n; i++) v[i].first = a[i], v[i].second = b[i];
	    sort(v.begin(), v.end(), custom);
	    long long int ans = 0, cur = 0;
	    for(int i = 0; i < n; i++) {
	        ans += (cur*v[i].second);
	        cur += v[i].first;
	    }
	    cout << ans << "\n";
	}
	return 0;
}

*/

//* Editorialist's Code->

/*

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    ind = [i for i in range(n)]
    ind.sort(key = lambda x: -a[x]/b[x])
    ans = prv = 0
    for i in ind:
        ans += b[i] * prv
        prv += a[i]
    print(ans)

*/