#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--)
    {
        ll div,minBalls;
        ll n,k;
        cin>>n>>k;
        if(n<=k)
        {
            if(n==1 & k==1) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        else
        {
            if(k%2==0)
            {
                div=k/2;
                minBalls=div*k+div;
                cout<<(n<minBalls?"No":"Yes")<<endl;
            }
            else
            {
                div=(k+1)/2;
                minBalls=div*k;
                cout<<(n<minBalls?"No":"Yes")<<endl;
            }
        }
    }
}