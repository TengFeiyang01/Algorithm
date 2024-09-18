import sys
from collections import Counter

RI = lambda: map(int, sys.stdin.readline().split())


def solve():
    n, m, k, l = RI()
    g = []
    fs = set()
    for _ in range(m):
        a, b = RI()
        if a == k or b == k:
            fs.add(a)
            fs.add(b)
        g.append((a, b))
    c = Counter()
    for a, b in g:
        if a not in fs and b in fs:
            c[a] += 1
        if b not in fs and a in fs:
            c[b] += 1
    sl = sorted((-v, k) for k, v in c.items())
    ans = []
    for i in range(l):
        if len(sl) > i:
            ans.append(sl[i][1])
        else:
            ans.append(0)
    print(*ans)


solve()