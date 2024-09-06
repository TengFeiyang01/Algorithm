import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from math import *
from collections import *


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


n, k = map(int, input().split())
x, y = map(int, input().split())

a = []
for i in range(n):
    a.append(tuple(map(int, input().split())))
a.sort(key=lambda x: x[2])

def GetL2Dist(x1, y1, x2, y2):
    return pow((x1 - x2) ** 2 + (y1 - y2) ** 2, 0.5)

f = [GetL2Dist(x, y, p, q) for p, q, _ in a]
g = [GetL2Dist(p[0], p[1], q[0], q[1]) for p, q in itertools.pairwise(a)]
dp = [inf] * k
dp[k - 1] = f[0]

for i in range(1, n):
    ndp = [inf] * k 
    mn = min(dp)  # 
    ndp[k - 1] = mn + f[i] + f[i - 1]
    for j in range(k - 1):
        ndp[j] = dp[j + 1] + g[i - 1]
    dp = ndp  
result = min(dp)

ans = (result + f[-1]) * 100 + 5

print(round(ans / 100, 1))