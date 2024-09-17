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
class Solution:
    def maxPoints(self, n, points, dependencies, k):
        adj = [[] for _  in range(n + 1)]
        d = [0] * n
        for u, v in dependencies:
            adj[v].append(u)
            d[u] += 1
        for i in range(n):
            adj[n].append(i)
        points.append(0)
        
        root = [i for i, x in enumerate(d) if x == 0]
        root.append(n)
        
        dp = [[0] * (k + 1) for _ in range(n + 1)]
        def dfs(u):
            for j in range(1, k + 1):
                dp[u][j] = points[u]
                
            for v in adj[u]:
                dfs(v)
                for j in range(k, 0, -1):
                    for p in range(j):
                        dp[u][j] = max(dp[u][j], dp[u][j - p] + dp[v][p])
        dfs(n)
        ans = 0
        for i in root:
            ans = max(ans, dp[i][k])
        return ans
        
    

def solve() -> None:
    s = Solution()
    n = sint()
    po = ints()
    adj = [ints() for _ in range(4)]
    k = sint()
    print(s.maxPoints(n, po, adj, k))


if __name__ == '__main__':
    solve()