//! https://www.codechef.com/START54D?order=desc&sortBy=successful_submissions
//! https://www.codechef.com/submit/CREDS

#include <iostream>

int main()
{
    int t; 
    scanf("%d",&t);
    while(t--)
    {
        int x,y,z;
        std::cin>>x>>y>>z;
        printf("%d\n",(x*4+y*2));
    }
}