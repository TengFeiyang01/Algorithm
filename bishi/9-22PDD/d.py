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
    for _ in range(int(input())):
        n = int(input())
        p = []
        for i in range(n):
            p.append(int(input()))
        maxCoupons = sum(p)  # 可能获得的最大兑换券数
        maxCoupons = ceil(maxCoupons / 100.0)  # 向上取整
        dp = [[sys.maxsize] * (int(maxCoupons) + 1) for _ in range(1010)]
        dp[0][0] = 0

        for i in range(1, n + 1):
            for j in range(int(maxCoupons) + 1):
                if dp[i-1][j] != sys.maxsize:
                    dp[i][j] = min(dp[i][j], dp[i-1][j] + p[i-1])
                    rest = dp[i-1][j] % 100 + p[i-1]
                    if rest >= 100 and j + 1 <= maxCoupons:
                        dp[i][j + 1] = dp[i-1][j] + p[i-1]

                if j + 1 <= maxCoupons and dp[i-1][j + 1] != sys.maxsize:
                    dp[i][j] = min(dp[i][j], dp[i-1][j + 1])

        res = sys.maxsize
        for i in range(int(maxCoupons) + 1):
            res = min(res, dp[n][i])
        print(res)

if __name__ == '__main__':
    solve()