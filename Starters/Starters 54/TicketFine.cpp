//! https://www.codechef.com/START54D?order=desc&sortBy=successful_submissions
//! https://www.codechef.com/submit/TCKTFINE

#include <iostream>

int main()
{
    int t; 
    scanf("%d",&t);
    while(t--)
    {
        int x,p,q;
        std::cin>>x>>p>>q;
        printf("%d\n", (p-q)*x);
    }
}