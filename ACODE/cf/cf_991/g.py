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
    adj = [[] for _ in range(n)]
    for i in range(n-1):
        u, v = mint()
        u -= 1
        v -= 1
        adj[u].append(v)
        adj[v].append(u)
    ans = -n
    def dfs(u, fa):
        mx1 = mx2 = 0
        for v in adj[u]:
            if v != fa:
                son = dfs(v, u)
                if son > mx1:
                    mx1, mx2 = son, mx1
                elif son > mx2:
                    mx2 = son
        nonlocal ans
        ans = max(ans, mx1 + mx2 + len(adj[u]) - 2)
        return mx1 - 2 + len(adj[u])
    dfs(0, -1)
    print(ans + 2)

if __name__ == '__main__':
    for _ in range(int(input())):
        solve()