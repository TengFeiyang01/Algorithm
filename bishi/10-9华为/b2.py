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


def solve() -> None:
    n = sint()
    a = ints()
    deg = [0] * n
    g = [[] for _ in range(n)]
    for i in range(n):
        v = sint()
        if v != -1:
            g[v - 1].append(i)
        deg[i] += 1
    dp = [0] * n
    h = []

    while h:
        cur = heappop(h)
        u = cur[1]

        for v in g[u]:
            deg[v] -= 1
            if deg[v] == 0:
                dp[v] = dp[u] + a[v]
                heappush(h, (dp[v], v))
    print(max(dp))

if __name__ == '__main__':
    solve()