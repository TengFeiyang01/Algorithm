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
    a = []
    for i in range(n):
        a.append(list(map(int, input().split())))
    m = int(input())
    dp = [[0] * (3) for _ in range(200000)]
    dp[a[0][1]][1] = a[0][0] - a[0][1]
    dp[2 * a[0][2]][2] = 2 * a[0][0] - 2 * a[0][2]

    for i in range(1, n):
        ndp = [[0] * (3) for _ in range(200000)]
        p, x, y = a[i]
        for j in range(m + 1):
            ndp[j][0] = max(dp[j])
            if j >= x:
                ndp[j][1] = max(ndp[j][1], max(dp[j - x]) + p - x)
            if j >= 2 * y:
                ndp[j][2] = max(ndp[j][2], max(dp[j - 2 * y]) + 2 * p - 2 * y)
        dp = ndp
    ans = 0
    for x in dp:
        ans = max(ans, max(x))
    print(ans)

if __name__ == '__main__':
    solve()