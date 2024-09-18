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


def solve() -> None:
    n, m = mint()
    dp = [0] * (m + 1)
    for i in range(n):
        x, y, s = mint()
        for j in range(m, x - 1, -1):
            for k in range(1, min(s, j // x) + 1):
                dp[j] = max(dp[j], dp[j - k * x] + k * y)
    print(dp[-1])

if __name__ == '__main__':
    solve()


