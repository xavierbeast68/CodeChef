#include <cstdio>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%s\n", ((x == y) ? "ANY" : (x>y?"NEW PHONE":"REPAIR")));
    }
}