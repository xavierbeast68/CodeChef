for _ in range(int(input())):
    a, b = map(int, input().split())
    d = b - a
    print('Yes' if d == 0 or a <= d else 'No')