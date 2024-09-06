s = input()
n = len(s)

cnt = [0] * (n + 1)
t = 0
for i in range(n):
    t += s[i] == '1'
    print(t - i, i)
    cnt[i + 1] += cnt[i] + (s[i] == '1')

from collections import defaultdict
pos = defaultdict(int)
for i in range(n, 0, -1):
    if cnt[i] not in pos:
        pos[cnt[i]] = i


res = n
ans = 0
from  math import  inf

L, R = -1, -1
for l in range(1, n + 1):
    r = pos[cnt[l]]
    r = max(r, l)
    now = r - l + 1 - (cnt[r] - cnt[l - 1])
    now += cnt[n] - cnt[r - 1]
    now += cnt[l - 1]
    if now > ans:
        ans = now
        res = min(res, r - l + 1)
        L, R = l, r
    if now == ans and r - l + 1 < res:
        L, R = l, r
print(ans)
print(L, R)


