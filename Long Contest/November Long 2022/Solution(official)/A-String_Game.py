# Editorialist's Python soln->

import collections
for _ in range(int(input())):
    n = int(input())
    s = input()
    d = collections.Counter(s)
    ans = 'Yes'
    for x in d.values():
        if x%2 == 1:
            ans = 'No'
    print(ans)