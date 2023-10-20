import heapq
import itertools
import sys
# from typing import Counter

# import itertools
# import math
# import os
# import random

from functools import lru_cache

# from heapq import heapify, heappop, heappush
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

sys.setrecursionlimit(3 * 10 ** 5)


def solve() -> None:
    n, m = mint()

    @lru_cache()
    def dfs(i, j, k, pre):
        if k < 0 or k > m:
            return 0
        if i < 0 or j < 0:
            return 0
        if i == 0 and j == 0:
            return k == 0 and pre == 0
        return (dfs(i - 1, j, k * 2, 1) + dfs(i, j - 1, k - 1, 0)) % MOD

    print(dfs(n, m, 2, 1))


if __name__ == '__main__':
    solve()

