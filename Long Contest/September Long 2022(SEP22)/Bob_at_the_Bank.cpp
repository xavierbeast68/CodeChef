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
        int w,x,y,z;cin>>w>>x>>y>>z;
        cout<<w+z*(x-y)<<"\n";
    }
	return 0;
}
