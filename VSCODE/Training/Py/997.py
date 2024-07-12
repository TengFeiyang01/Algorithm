import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
# from typing import Counter

# import math
# import random

# from io import BytesIO, IOBase
# from string import *

# region fastio
input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

# MOD = 998244353
MOD = 10 ** 9 + 7
# DIR = ((-1, 0), (0, 1), (1, 0), (0, -1))

# sys.setrecursionlimit(3 * 10 ** 5)


def solve() -> None:
    n, m = mint()
    dp = [0] * (m + 1)
    for _ in range(n):
        x, y = mint()
        for j in range(m, x - 1, -1):
            dp[j] = max(dp[j], dp[j - x] + y)
    print(dp[-1])

   


if __name__ == '__main__':
    solve()
