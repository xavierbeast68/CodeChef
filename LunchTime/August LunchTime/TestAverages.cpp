#include <iostream>
using namespace std;
#define avg(a,b) ((a+b)/2)

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int A,B,C;
	    cin>>A>>B>>C;
	    int c=avg(A,B);
	    int d=avg(B,C);
	    int e=avg(A,C);
	    if(c<35 || d<35 || e<35)
	    {
	        cout<<"Fail"<<endl;
	    }
	    else
	    {
	        cout<<"Pass"<<endl;
	    }
	}
	return 0;
}
