#include <iostream>
using namespace std;

int main() 
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

	int t;cin>>t;
    while(t--)
    {
        int n,m,x;cin>>n>>m>>x;
        cout<<(2*n+2*m)*x<<"\n";
    }
	return 0;
}
