//! Problem Code: XOR_PAL

#include <iostream>
using namespace std;
// #define debug (cout<<"==Testing=="<<endl)

void equal(string st, int *a, int *b, int *c)
{
    if (st[*a] == st[(*a) + 1] && st[*b] == st[*b - 1] && (*a)<(*b))
    {
        // debug;
        (*a)+=2;
        (*b)-=2;
        equal(st, a, b, c);
        // (*c)++;
        return;
    }
    // else
    // {
        // cout<<"==Testing2=="<<endl;
        (*c)++;
    //     return;
    // }
}

int main()
{
    // your code goes here
    // int t;
    // cin >> t;
    // while (t--)
    // {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int i = 0, j = n - 1;
        int count = 0;
        while (i < j)
        {
            if (s[i] != s[j])
            {
                equal(s, &i, &j, &count);
            }
            i++;
            j--;
        }
        cout << count << endl;
    // }
    return 0;
}

//! optimized code
//* Submission by somesh_1 ; Submission ID: 72659923
/*
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
#define all(_obj) _obj.begin(),_obj.end()
#define F first
#define S second
#define pll pair<ll, ll> 
#define vll vector<ll>
const int N=1e5+11,mod=1e9+7;
ll max(ll a,ll b) {return ((a>b)?a:b);}
ll min(ll a,ll b) {return ((a>b)?b:a);}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void sol(void)
{
    int n,ans=0;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n/2;i++)
    {
        if(s[i]!=s[n-1-i])
        ans++;
    }
    cout<<(ans+1)/2<<'\n';
    return ;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int test=1;
    cin>>test;
    while(test--) sol();
}
*/