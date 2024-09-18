import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from math import inf
sys.setrecursionlimit(100000)


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
    
    ans = inf

    def dfs(u, fa):
        s = 1
        res = 0
        for v in adj[u]:
            if v != fa:
                t = dfs(v, u)
                res = max(res, t)
                s += t
        nonlocal ans
        res = max(res, n - s)
        ans = min(ans, res)
        return s
        
    dfs(0, -1)
    print(ans)

if __name__ == '__main__':
    solve()