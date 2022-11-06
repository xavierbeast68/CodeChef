for _ in range(int(input())):
    n = int(input())
    ones = 0
    ans = 'YES'
    for c in input():
        if c == '1':
            ones += 1
        else:
            if ones % 2 == 1:
                ans = 'NO'
            ones = 0
    if ones % 2 == 1 and n > 1:
        ans = 'NO'
    print(ans)