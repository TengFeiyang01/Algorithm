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


n, m = map(int, input().split())
adj = [[] for _ in range(n)]

for i in range(m):
    x, y = map(int, input().split())
    adj[x].append(y)

ok = False
def dfs(u, x):
    global ok
    for v in adj[u]:
        if v == x:
            ok = True
        dfs(v, x)
ans = []
q = int(input())
for i in range(q):
    x, y = map(int, input().split())
    dfs(x, y)
    if ok:
        ans.append(1)
    else:
        ans.append(0)
    ok = False
    
print(q)
for x in ans:
    print(x)
    




# inf = 10 ** 10
# D = int(input())
# N = int(input())
# last = [(0, 0)]
# for i in range(N):
#     x, y = map(int, input().split())
#     last.append((x, y + 1))
# last.append((D, 0))

# dp = [0] + [inf for _ in range(N + 1)]

# for i in range(1, N + 2):
#     for j in range(i - 1, -1, -1):
#         if last[i][0] - last[j][0] <= 1000:
#             dp[i] = min(dp[j] + last[i][1], dp[i])
#         else:
#             break    
# print(dp[-1] + D // 100)