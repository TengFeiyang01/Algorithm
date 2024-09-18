import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
# from typing import Counter
# import math
# import random
input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))
from math import inf


def solve() -> None:
    input()
    n, q = mint()
    a = ints()
    t = ints()

    dp = [inf] * (n + 1)
    for p, x in zip(a, t):
        dp[p] = x
    for i in range(1, n + 1):
        dp[i] = min(dp[i], dp[i - 1] + 1)
    for i in range(n - 1, 0, -1):
        dp[i] = min(dp[i], dp[i + 1] + 1)
    print(*dp[1:])


if __name__ == '__main__':
    _ = sint()
    for i in range(_):
        solve()
    