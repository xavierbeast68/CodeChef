
// ! https://stackoverflow.com/questions/37777053/how-to-convert-integer-to-double-implicitly

#include <bits/stdc++.h>
using namespace std;
#define avg(a,b) ((a+b+0.0)/2) 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    cin>>t;
    while(t--)
    {
        int A,B,C;
        cin>>A>>B>>C;
        cout<<(avg(A,B)>C?"Yes":"No")<<endl;
    }

    //cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;

}