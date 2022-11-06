for _ in range(int(input())):
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    s = sum(a)
    while q > 0:
        l, r = map(int, input().split())
        s += l%2 == r%2
        q -= 1
    print(s)