//* setter's code->

#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
typedef set<string> ss;
typedef vector<int> vs;
typedef map<int, char> msi;
typedef pair<int, int> pa;
typedef long long int ll;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans += b[i] - a[i];
		ans = (ans % 26 + 26) % 26;
		cout << min(ans, abs(26 - ans)) << "\n";
	}

	return 0;
}


// python code->
/*

for _ in range(int(input())):
    n, a, b = int(input()), input(), input()
    ans = 0
    for i in range(n):
        ans += ord(a[i]) - ord(b[i]) + 26
    print(min(ans%26, (-ans)%26))

*/