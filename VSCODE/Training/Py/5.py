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
    a = []
    for i in range(n):
        u, v, s = mint()
        k = 1
        while s >= k:
            s -= k
            a.append((u * k, v * k))
            k *= 2
        if s:
            a.append((s * u, s * v))
    dp = [0] * (m + 1)
    for x, y in a:
        for j in range(m, x - 1, -1):
            dp[j] = max(dp[j], dp[j - x] + y)
    print(dp[-1])



if __name__ == '__main__':
    solve()