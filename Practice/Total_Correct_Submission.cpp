//* Codechef
//* Date-> 15/11/2022
//* URL-> https://www.codechef.com/problems/TOTCRT

//* https://www.geeksforgeeks.org/sorting-a-map-by-value-in-c-stl/

#include <bits/stdc++.h>
using namespace std;
#define int long long

bool cmp(pair<string, int>& a,pair<string, int>& b)
{
    return a.second < b.second;
}

void solve()
{
    int n;cin>>n;
    map<string,int> mp;
    for(int i=0;i<3*n;i++)
    {
        string s;cin>>s;
        int x;cin>>x;
        if(mp.find(s)!=mp.end())
        {
            mp[s]=mp[s]+x;
        }
        else
        {
            mp.insert({s,x});
        }
    }
    
    vector<pair<string,int>> a;
    for (auto& it : mp) 
    {
        a.push_back(it);
    }
    sort(a.begin(),a.end(),cmp);
    
    for(auto i: a)
    {
        cout<<i.second<<" ";
    }
    cout<<endl;
}

signed main() {
	// your code goes here
	int t=1;cin>>t;
	while(t--)
	{
	    solve();
	}
	return 0;
}
