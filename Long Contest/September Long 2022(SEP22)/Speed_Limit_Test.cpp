// #include <iostream>
// using namespace std;

// int main() 
// {
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt","r",stdin);
//         freopen("output.txt","w",stdout);
//     #endif

// 	int t;cin>>t;
//     while(t--)
//     {
//         int a,x,b,y;cin>>a>>x>>b>>y;
//         cout<<((a/x)==(b/y)?"Equal":((a/x)>(b/y)?"Alice":"Bob"))<<"\n";
//     }
// }

#include <iostream>
using namespace std;

int main() 
{
	int t;cin>>t;
    while(t--)
    {
        int a,x,b,y;cin>>a>>x>>b>>y;
        float s1=(float)a/x;
        float s2=(float)b/y;
        if(s1==s2) cout<<"Equal"<<endl;
        else if(s1>s2) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
}
