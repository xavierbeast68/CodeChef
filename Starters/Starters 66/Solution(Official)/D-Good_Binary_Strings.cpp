//$ URL-> https://www.codechef.com/problems/GOODBINSTR
//* Setter's Code->

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        if (s[0] == s[s.size()-1])
        {
            cout << s.size()-2 << "\n";
        }
        else
        {
            cout << "2\n";
        }
    }
}

//* Another soln->
/*

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        int n=s.size();
        int zero_one = 0;
        int one_zero = 0;

        for(int i=1;i<n;i++)
        {
            if(s[i-1] == '0' && s[i] == '1')
            {
                zero_one++;
            }
            else if(s[i-1] == '1' && s[i] == '0')
            {
                one_zero++;
            }
        }

        if (zero_one == one_zero)
        {
            cout << n-2 << "\n";
        }
        else
        {
            cout << 2 << '\n';
        }
    }
}

*/

//* Python Code->
/*

def calc(s):
	n = len(s)
	zo, oz = 0, 0
	for i in range(n-1):
		if s[i] == s[i+1]: continue
		if s[i] == '0': zo += 1
		else: oz += 1
	return zo - oz

for _ in range(int(input())):
	s = input()
	if len(s) == 1: print(1)
	else:
		if calc(s) == 0: print(len(s)-2)
		else: print(int(calc(chr(97 - ord(s[0])) + s[1:]) == 0) + int(calc(s[:len(s)-1] + chr(97 - ord(s[-1]))) == 0))

*/