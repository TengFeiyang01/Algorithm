n = int(input())
t = input()
from collections import *
cnt = Counter()
cnt[0] = -1
s = 0
ans = 0
for i in range(n):
    c = t[i]
    if c == 'A':
        s += 1
    else:
        s -= 1
    if s not in cnt:
        cnt[s] = i
    else:
        ans = max(ans, i - cnt[s])
print(ans)