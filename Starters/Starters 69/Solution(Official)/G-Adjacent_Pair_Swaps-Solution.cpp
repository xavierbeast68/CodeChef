/*
Authors: utkarsh_25dec
Testers: iceknight1093, mexomerf
Editorialist: iceknight1093
*/

//$ URL-> https://www.codechef.com/problems/ADJPAIRSWAP
/*
> Difficulty Rating :
% 3300 
*/

//* Setter's Code->

//Utkarsh.25dec
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define vl vector <ll>
#define all(c) (c).begin(),(c).end()
using namespace std;
ll power(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll modInverse(ll a){return power(a,mod-2);}
const int N=500023;
bool vis[N];
vector <int> adj[N];
int sumN=0;
vector <pair<int,int>> opers;
int A[N];

// Applying operation on (i,j)
void apply(int i,int j)
{
    opers.pb(mp(i,j));
    swap(A[i],A[j]);
    swap(A[i+1],A[j+1]);
}

// Moving all zeros to left one by one
void placeZeros(int n)
{
    // keep will store the position of leftmost 1
    int keep=0;
    for(int i=2;i<=n;i++)
    {
        if(A[i]==1 || A[i-1]==0)
            continue;
        if(A[i-1]==1)
        {
            while(A[keep]==0)
                keep++;

            if(i==n) // Move left once and then move it to required place
            {
                apply(n-3,n-1);
                apply(keep,n-2);
                continue;
            }

            if(keep+1<i) // Directly move it to required place
                apply(keep,i);
            else // Move right once and then move it to required place
            {
                apply(i,i+2);
                apply(keep,i+2);
            }
        }
    }
}
void solve()
{
    opers.clear();
    int n;
    cin>>n;
    int cnt0=0,cnt1=0;
    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
        if(A[i]==0)
            cnt0++;
        else
            cnt1++;
    }

    // All Same. Already Sorted
    if(max(cnt0,cnt1)==n)
    {
        cout<<0<<'\n';
        return;
    }

    // We will try to place the character with less count
    if(cnt0<=cnt1)
        placeZeros(n);
    else
    {
        // Reversing and Complimenting the array
        int B[n+1];
        for(int i=1;i<=n;i++)
            B[i]=1-A[n+1-i];
        for(int i=1;i<=n;i++)
            A[i]=B[i];
            
        placeZeros(n);
        // Adjusting the operations as we had reversed the array
        for(int i=0;i<opers.size();i++)
            opers[i]=mp(n-opers[i].second,n-opers[i].first);
    }

    cout<<opers.size()<<'\n';
    for(auto it:opers)
        cout<<it.first<<' '<<it.second<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int T;
    cin>>T;
    while(T--)
        solve();
}

//* Editorialist's Python Code->
/*
for _ in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	ones = [i for i in range(n) if a[i] == 1]
	swaps = []
	def operate(x, y): # x < y
		assert 0 <= x < n-1
		assert x+1 < y < n-1
		a[x], a[y] = a[y], a[x]
		a[x+1], a[y+1] = a[y+1], a[x+1]
		swaps.append((x, y))
		
	for i in reversed(range(n)):
		if len(ones) == 0: break
		if ones[-1] == i:
			ones.pop()
			continue
		if 0 < ones[-1] < i-1:
			u = ones.pop()
			if a[u-1] == 1: ones.pop()
			operate(u-1, i-1)
			if a[i-1] == 1: ones.append(i-1)
		elif len(ones) == 1:
			if ones[-1] == 0: # Case 100000...01111...
				if a[4] == 0: # Case 1000...011111
					operate(0, 2)
					operate(1, i-1)
				elif a[3] == 0:
					operate(0, 2)
					operate(3, 5)
					operate(2, 5)
				elif a[2] == 0: # Case 10011111...
					operate(0, 2)
					operate(1, 3)
				else: # 101111...
					operate(0, 2)
					operate(0, 3)
			else:
				if i >= 4:
					operate(i-3, i-1)
					operate(i-4, i-1)
				else:
					operate(i, i+2)
					operate(i-1, i+2)
			ones.pop()
		# Now ones[-1] == i-1
		elif ones[-2] > 0:
			ones.pop()
			u = ones.pop()
			if a[u-1] == 1: ones.pop()
			operate(u-1, i-1)
			ones.append(u-1)
			if a[i-1] == 1: ones.append(i-1)
		else: # a[0] = a[i-1] = 1, and these are the only 2
			if i == 2: # Case 11011111...
				operate(0, 2)
			elif i == 3: # Case 1010111...
				operate(0, 3)
				operate(1, 4)
			else: # Case 100...10111...
				operate(0, i-2)
				operate(i-3, i-1)
				if i > 4: operate(0, i-2)
			break
	print(len(swaps))
	for x, y in swaps:
		print(x+1, y+1)
*/