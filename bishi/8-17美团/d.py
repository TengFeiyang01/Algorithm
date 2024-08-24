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

MOD = 1000000007
def solve() -> None:
    n, k, t = map(int, input().split())
    a = list(map(int, input().split()))
    p = 100 * n
    mx = p * 2
    dp = [[0] * (mx + 2) for _ in range(k + 1)]
    dp[0][p] = 1
    for i in range(n):
        v = a[i]
        ndp = [[0] * (mx + 2) for _ in range(k + 1)]
        for j in range(k + 1):
            for s in range(mx + 1):
                if dp[j][s] == 0: continue
                if j < k and s >= v:
                    ndp[j + 1][s - v] = (ndp[j + 1][s - v] + dp[j][s]) % MOD
                if s + v <= mx:
                    ndp[j][s + v] = (ndp[j][s + v] + dp[j][s]) % MOD
        dp = ndp
    ans = 0
    for i in range(k + 1):
        for j in range(p, min(mx, p+t)+1):
            ans = (ans + dp[i][j]) % MOD
    print(ans)

if __name__ == '__main__':
    solve()