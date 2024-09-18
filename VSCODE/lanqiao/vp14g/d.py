import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from math import inf


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve() -> None:
    n, A, B = mint()
    a = ints()
    dp = [[[0] * (B + 1) for _ in range(A + 1)] for __ in range(2)]
    f, g = 0, 1
    for i in range(n):
        f, g = g, f
        for j in range(A + 1):
            for k in range(B + 1):
                if j - a[i] >= 0:
                    dp[f][j][k] = max(dp[f][j][k], dp[g][j - a[i]][k] + a[i], dp[g][j][k])
                if k >= a[i]:
                    dp[f][j][k] = max(dp[f][j][k],dp[g][j][k - a[i]] + a[i], dp[g][j][k])
    print(dp[f][-1][-1])

if __name__ == '__main__':
    solve()