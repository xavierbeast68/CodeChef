'''
Authors: notsoloud
Testers: iceknight1093, mexomerf
Editorialist: iceknight1093
'''

# $ URL-> https://www.codechef.com/problems/PERMUTATION
#> Difficulty Rating :
#% 1197 


#* Editorialist's Code(Python)->

for _ in range(int(input())):
    n = int(input())
    a = sorted(list(map(int, input().split())))
    ans = sum(i+1 - a[i] for i in range(n))
    for i in range(n):
        if a[i] > i+1: ans = -1
    print(ans)