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
    a = input()
    b = input()
    c = input()
    na, nb = len(a), len(b)
    dp = [[na + nb + 1] * (nb + 1) for _ in range(na + 1)]
    dp[0][0] = 0
    for i in range(na + 1):
        for j in range(nb + 1):
            k = i + j
            if i < na:
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + int(a[i] != c[k]))
            if j < nb:
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + int(b[j]!= c[k]))
    print(dp[na][nb])


if __name__ == '__main__':
    for _ in range(int(input())):
        solve()