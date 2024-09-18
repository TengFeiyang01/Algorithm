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
    n, m, k = mint()
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    for _ in range(k):
        c, d = mint()
        for i in range(n, c - 1, -1):
            for j in range(m - 1, d - 1, -1):
                dp[i][j] = max(dp[i][j], dp[i - c][j - d] + 1)

    now = m - 1
    while dp[n][now - 1] == dp[n][m - 1] and now > 0:
        now -= 1
    print(dp[n][m - 1], m - now, end=' ')
    

if __name__ == '__main__':
    solve()