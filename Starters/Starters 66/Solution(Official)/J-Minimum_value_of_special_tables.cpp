//$ URL-> https://www.codechef.com/problems/MNVST
//! Pre-requisite->
//^ Dynamic Programming

/*
* Author: mehrzad minaei
* Testers: Hriday, Utkarsh Gupta
* Editorialist: Nishank Suresh
*/

//* Setter's Code->
#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 10;
int dp[maxn][maxn];

int main () {
    ios_base::sync_with_stdio(false), cin.tie(0);

    memset(dp, 63, sizeof(dp));
    for (int i = 0; i < maxn; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i < maxn; i++) {
        for (int j = 1; j < maxn; j++) {
            dp[i][j] = dp[i][j-1];
            if (j <= i) dp[i][j] = min(dp[i][j], dp[i-j][j-1] + j*j);
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        n = min(n, m);
        cout << dp[n][n];
        if (t) cout << "\n";
    }

    return 0;
}

//* Editorialist's Python Code->
/*

inf = 10 ** 18
maxn = 5005
dp = [inf]*(maxn+1)
ans = [0]*(maxn+1)
dp[0] = 0
for i in range(1, maxn+1):
    for j in reversed(range(i, maxn+1)):
        dp[j] = min(dp[j], dp[j-i] + i*i)
    ans[i] = dp[i]

for _ in range(int(input())):
    n, m = map(int, input().split())
    n = min(n, m)
    ans = 0
    for i in range(1, n+1):
        ans = max(ans, i-1 + (n-i+1)**2)
    print(ans)

*/