
n, e, o = list(map(int, input().split()))

g = []
g.append([])
for i in range(n):
    r = list(map(int, input().split()))
    g.append(r[1:])

import heapq
from math import inf
# 3 4 5
# 

hp = []
dp = [inf] * (n + 1)

dp[e] = 0
heapq.heappush(hp, (e, 0))

while len(hp) > 0:
    u, w = heapq.heappop(hp)
    if dp[u] != w:
        continue
    for (i, v) in enumerate(g[u]):
        if i == 0:
            if dp[v] > dp[u]:
                dp[v] = dp[u]
                heapq.heappush(hp, (v, dp[v]))
        else:
            if dp[v] > dp[u] + 1:
                dp[v] = dp[u] + 1
                heapq.heappush(hp, (v, dp[v]))

print (-1 if dp[o] == inf else dp[o])


def get(x, y, z):
    


# 3 2 1
# 2 2 3
# 2 3 1
# 2 1 2