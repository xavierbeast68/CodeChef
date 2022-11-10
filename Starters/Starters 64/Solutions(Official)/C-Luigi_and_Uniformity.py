from math import gcd
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    g = a[0]
    for x in a:
        g = gcd(x, g)
    print(n - a.count(g))