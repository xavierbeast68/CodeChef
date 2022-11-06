/**
 * @author xavierbeast68
 * Problem Name- Distinct Numbers ( Codechef Starters 60)
 * Problem Link- https://www.codechef.com/submit/DISKMOV
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */


//* Tester's Solution
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n, k;
	    cin >> n >> k;
	    long long int ans1 = 0, ans2 = 0;
	    int a[n];
	    for(int i = 0; i < n; i++) cin >> a[i];
	    sort(a, a + n);
	    vector<int> missing;
	    int now = 0;
	    for(int i = 1; i <= 2*n; i++) {
	        if(a[now] == i) now++;
	        else missing.push_back(i);
	    }
	    for(int i = 0 ; i < k ; i++) ans1 += max(0, a[n - 1] - missing[i]);
	    for(int i = 0 ; i < k - 1 ; i++) ans2 += max(0, 2*n - missing[i]);
	    cout << max(ans1, ans2) << "\n";
	}
	return 0;
}
*/