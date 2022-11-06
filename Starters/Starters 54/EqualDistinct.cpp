//! https://www.codechef.com/START54D?order=desc&sortBy=successful_submissions
//! https://www.codechef.com/submit/EQDIS?tab=statement

//* My soln => WA
#include <iostream>
typedef long long ll;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ll n;
        std::cin >> n;
        ll a[n + 1];
        ll b[n + 1];
        for (int i = 1; i <= n; i++)
        {
            std::cin >> a[i];
            b[a[i]]++;
        }
        if(n%2==1)
        {
            printf("NO\n");
        }
        else
        {
            int check = 0;
            for (int i = 0; i <= n; i++)
            {
                if (b[i] == n - 1)
                {
                    check = 1;
                }
            }
            if (check == 0)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}

/*
//* Submission ID: 72935301

#include <iostream>
#include<cmath>
#include<ctime>
#include <string>
#define ll long long
using namespace std;
int setbit(ll n){
    int i=0;
    while(n>0){
        i+=(n&1)==1?1:0;
        n>>=1;
    }
    return i;
}
int main() {
	// your code goes here
	int Test;
	ll t,n,s=0;
	cin>>Test;
	while(Test--){
	    s=0;
	    cin>>n;
	    int x;
	    int arr[n]={0};
	    for(int i=0;i<n;i++){
	        cin>>x;
	        arr[x-1]++;
	    }
	    if(n&1){
    	    for(int i =0;i<n;i++){
    	        if(arr[i]>1){
    	            s=1;
    	            break;
    	        }
    	    }
    	    if(s==1)    cout<<"yes";
	        else    cout<<"no";
	    }else{
	        cout<<"yes";
	    }
	    cout<<endl;
	    
	}
	return 0;
}
*/

/*
//* Submission ID: 72937473

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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    set<int> s;
    map<int, int> mp;
    for (int x : a) {
      s.insert(x);
      mp[x]++;
    }
    if ((int) s.size() % 2 == 0) {
      cout << "YES\n";
      continue;
    }
    bool ok = false;
    for (auto it = mp.begin(); it != mp.end(); it++) {
      if (it->second > 1) {
        ok = true;
        break;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}

*/

/*
//* Submission ID: 72938542

//code by animesh kumar/tron 

#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define ld long double


const int MAXN = 1e5 + 5;
const ll M = 1e9 + 7;


// int primeornot(int n){
// 	int flag=0;
// 	for(int i=0;i*i<=n;i++){
// 		if(n%i==0){
// 			flag++;
// 			if(i!=n/i){
// 				flag++;
// 			}
// 		}
// 	}
// 	return flag;
// }

//code by animesh kumar/tron 

// code to find all the prime number in a range n
// this is SIEVE OF ERATHOSTHEMES algorithm


// int n;
// cin>>n;
// vector<int>prime(n+1,1);

// prime[1]=0;
// for(int i=2;i<=n;i++){
// 	if(!prime[i])continue;
// 	for(int j=i*i;j<=n;j+=i){
// 		prime[j]=0;
// 	}
// }



int gcd(int a,int b){
	if(a==0){
		return b;
	}
	return gcd(b%a,a);
}

//code by animesh kumar/tron 


void do_it_here() {

//stop stocking my solution u mf!	
    int n;
    cin>>n;
    int arr[n];
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }
    int one=0;
    int even=0;
    // int odd=0;
    for(auto it:mp){
        if(it.second==1){
            one++;
        }
        else{
            even++;
        }
    }
    if(one%2==0){
        cout<<"YES"<<endl;
    }
    else if(one%2==1 and even>0){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int testcas = 23;
    cin >> testcas;
    
    for (int t = 1; t <= testcas; t++) {
        do_it_here();

    }
}
//code by animesh kumar/tron
//code by animesh kumar

*/