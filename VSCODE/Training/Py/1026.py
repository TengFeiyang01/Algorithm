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
    m, n = sint(), sint()
    dp = [0] * (m + 1)
    for i in range(n):
        x = sint()
        for j in range(m, x - 1, -1):
            dp[j] = max(dp[j], dp[j - x] + x)
    print(m - dp[-1])

if __name__ == '__main__':
    solve()