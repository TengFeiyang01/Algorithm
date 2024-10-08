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
    for _ in range(n):
        x, y = mint()
        for j in range(x, m + 1):
            dp[j] = max(dp[j], y + dp[j - x])

    print(dp[-1])

if __name__ == '__main__':
    solve()