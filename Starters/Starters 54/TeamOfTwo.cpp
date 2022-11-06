//! https://www.codechef.com/START54D?order=desc&sortBy=successful_submissions
//! https://www.codechef.com/submit/TEAMOF2


//! Submission ID: 72938437 
//* Submission by i_emerge16
//tags: STL, Vectors, Set, and there operations
#include <bits/stdc++.h> 
using namespace std;

#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      for (int j = 0; j < k; j++) {
        int x;
        cin >> x;
        a[i].push_back(x);
      }
    }
    bool ok = false;
    for (int i = 0; i < n && !ok; i++) {
      for (int j = i + 1; j < n && !ok; j++) {
        set<int> s;
        for (int k = 0; k < (int) a[i].size(); k++) {
          s.insert(a[i][k]);
        }
        for (int k = 0; k < (int) a[j].size(); k++) {
          s.insert(a[j][k]);
        }
        if ((int) s.size() == 5) {
          ok = true;
        }
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}

//! Submission ID: 72937679
/*
#include<bits/stdc++.h>
#define ll long long int
#define bg() begin()
#define ed() end()
#define pb push_back
#define acc() accumulate()
#define mp make_pair
#define rep(i,a,n) for(int i=a;i<n;i++)
using namespace std;
int lcm(int &a, int &b) { return a * b / gcd(a, b); }
signed main()
{
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
int t; cin>>t;
while(t--)
{
    int n,e,en,fg=0; cin>>n;
    vector<vector<int>>V(n);
    rep(i,0,n)
    {
        cin>>e;
        rep(j,0,e)
        {
            cin>>en; V[i].pb(en);
        }
    }
    rep(i,0,n)
    {
        rep(j,i+1,n)
        {
            set<int>st;
            rep(k,0,V[i].size())
            {st.insert(V[i][k]);}
            rep(k,0,V[j].size())
            {st.insert(V[j][k]);}
            // for(int e:st) cout<<e<<" ";
            if(st.size()==5) {fg=1;}
            // cout<<st.size()<<" ";
            // cout<<"\n";
        }
    }
    // cout<<fg<<"\n";
    if(fg==1) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
}
return 0;
}
*/