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
    n = int(input())
    adj = [[] for _ in range(n)]
    for i in range(n-1):
        x, y = mint()
        adj[x - 1].append(y - 1)
        adj[y - 1].append(x - 1)
    size = [0] * n
    ans = 0
    cnt = Counter()
    def dfs(u, fa):
        nonlocal size, ans, cnt
        for v in adj[u]:
            if v == fa: continue
            dfs(v, u)
            size[u] += 1
        ans += cnt[size[u]]
        cnt[size[u]] += 1
        return size[u]
    
    dfs(0, -1)
    
    print(ans)
    
if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        solve()