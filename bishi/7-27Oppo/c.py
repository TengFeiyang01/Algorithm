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
    for i in range(n - 1):
        x, y = mint()
        adj[x - 1].append(y - 1)
        adj[y - 1].append(x - 1)
    m = 0
    def dfs(u, fa, c):
        nonlocal m
        if not c:
            m += 1
        for v in adj[u]:
            if v != fa:
                dfs(v, u, not c)
    dfs(0, -1, False)
    print(m * (n - m) - (n - 1))
    

if __name__ == '__main__':
    solve()