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

sys.setrecursionlimit(1000000)

def solve() -> None:
    n = sint()
    a = ints()
    adj = defaultdict(list)
    for i in range(1, n):
        x = a[i] + i
        adj[x].append(x + i)
    ans = n
    vis = set()
    def dfs(x):
        vis.add(x)
        nonlocal ans
        ans = max(ans, x)
        for v in adj[x]:
            if v in vis:
                continue
            dfs(v)
    dfs(n)
    print(ans)
    
if __name__ == '__main__':
    for _ in range(sint()):
        solve()