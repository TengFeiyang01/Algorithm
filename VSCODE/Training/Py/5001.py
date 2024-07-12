import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from collections import defaultdict, deque
# from typing import Counter
# import math
# import random

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

sys.setrecursionlimit(3 * 10 ** 5)


def solve() -> None:
    n = sint()
    adj = [[] for _ in range(n)]
    a = [0] * n
    for i in range(n):
        c, fa = mint()
        a[i] = c
        if fa: 
            adj[fa - 1].append(i)
            adj[i].append(fa - 1)

    son = [-1] * n
    size = [0] * n

    def dfs1(u, fa):
        size[u] = 1
        for v in adj[u]:
            if v == fa: continue
            dfs1(v, u)
            size[u] += size[v]
            if son[u] == -1 or size[v] > size[son[u]]:
                son[u] = v
    dfs1(0, -1)

    f = defaultdict(int)
    g = defaultdict(int)

    def clear(u, fa):
        g[f[a[u]]] = 0
        f[a[u]] = 0
        for v in adj[u]:
            if v != fa:
                clear(v, u)
    
    def add(u, fa):
        f[a[u]] += 1
        g[f[a[u]] - 1] -= 1
        g[f[a[u]]] += 1
        for v in adj[u]:
            if v != fa:
                add(v, u)
    
    ans = 0

    def dfs(u, fa):
        nonlocal ans
        for v in adj[u]:
            if v != son[u] and v != fa:
                dfs(v, u)
                clear(v, u)

        if son[u] != -1:
            dfs(son[u], u)

        f[a[u]] += 1
        g[f[a[u]] - 1] -= 1
        g[f[a[u]]] += 1
        for v in adj[u]:
            if v != son[u] and v != fa:
                add(v, u)

        if g[f[a[u]]] * f[a[u]] == size[u]:
            ans += 1    
    
    dfs(0, -1)
    print(ans)

if __name__ == '__main__':
    solve()