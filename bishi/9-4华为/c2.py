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
    n, k = map(int, input().split())
    x, y = map(int, input().split())
    
    points = [list(map(int, input().split())) for _ in range(n)]
    points.sort(key=lambda x: x[2])
    
    def getdist(x1, y1, x2, y2):
        return ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5
    
    f = [getdist(x, y, xi, yi) for xi, yi, le in points]
    g = []
    for i in range(1, n):
        pi, pj = points[i - 1], points[i]
        g.append(getdist(pi[0], pi[1], pj[0], pj[1]))
    
    dp = [[inf] * k for i in range(n)]
    dp[0][k - 1] = f[0]
    for i in range(1, n):
        mn = min(dp[i - 1])
        dp[i][k - 1] = mn + f[i] + f[i - 1]
        for j in range(k - 1):
            dp[i][j] = dp[i - 1][j + 1] + g[i - 1]
    
    ans = (min(dp[-1]) + f[-1]) * 100
    
    print(round(ans / 100, 1))

if __name__ == '__main__':
    solve()