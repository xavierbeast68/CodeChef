/*
Author: justfun21
Testers: iceknight1093, mexomerf
Editorialist: iceknight1093
*/

//$ URL-> https://www.codechef.com/problems/CHEFDINE
/*
> Difficulty Rating :
% 1438 

! Pre-requisites->
> Sorting
*/


//* Setter's Code->

#include <bits/stdc++.h>
using namespace std;


int main(){
    // setIO("input");
    ios_base::sync_with_stdio(false);
    cin.tie();cout.tie();
    long long TT = 1;
    long long suma = 0;
    cin>>TT;
    for(long long TR = 1;TR <= TT;TR++){
        long long n,k;
        cin>>n>>k;
        suma+=n;
        assert(n>=1 and n<=100000);
        assert(k>=1 and k<=100000);
        vector<long long>a(n),b(n);
        for(long long i=0;i<n;i++){
            cin>>a[i];
            assert(a[i]>=1 and a[i]<=100000);
        }
        for(long long i=0;i<n;i++){
            cin>>b[i];
            assert(b[i]>=0 and b[i]<=100000);
        }
        map<long long,long long>mp;
        for(long long i=0;i<n;i++){
            mp[a[i]] = 10000007;
        }                 
        for(long long i=0;i<n;i++){
            mp[a[i]] = min(mp[a[i]],b[i]);
        }
        vector<long long>time;
        for(auto it:mp){
            if(it.second!=10000007){
                time.push_back(it.second);
            }
        }    
        sort(time.begin(),time.end());
        if(time.size()<k){
            cout<<-1<<"\n";
            continue;
        }
        long long ans = 0;
        for(long long i=0;i<k;i++){
            ans+=time[i];
        }
        cout<<ans<<"\n";
    } 
    assert(suma>=1 and suma<=100000);
    return 0;
}

//* Tester's Code->
/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n], b[n];
        map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (mpp.find(a[i]) == mpp.end())
            {
                mpp[a[i]] = b[i];
            }
            else
            {
                mpp[a[i]] = min(mpp[a[i]], b[i]);
            }
        }
        vector<int> v;
        for (auto &it : mpp)
        {
            v.push_back(it.second);
        }
        sort(v.begin(), v.end());
        int sum = -1;
        if (v.size() >= k)
        {
            sum = 0;
            for (int i = 0; i < k; i++)
            {
                sum += v[i];
            }
        }
        cout << sum << "\n";
    }
    return 0;
}
*/

//* Editorialist's Code(Python)->
/*
for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    least = [10**12 for i in range(10**5 + 5)]
    for i in range(n): least[a[i]] = min(least[a[i]], b[i])
    ans = sum(sorted(least)[0:k])
    print(ans if ans < 10**12 else -1)
*/