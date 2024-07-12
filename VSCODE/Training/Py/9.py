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

# def solve() -> None:
#     n, m = mint()
#     dp = [0] * (m + 1)
#     a = [[] for _ in range(n)]
#     for i in range(n):
#         s = sint()
#         for j in range(s):
#             a[i].append((x, y := mint()))

#     for _ in range(n):
#         for j in range(m):
#             for x, y in a[i]:
#                 if j >= x:
#                     dp[j] = max(dp[j], dp[j - x] + y)
#     print(dp[-1])



def solve() -> None:
    n, m = mint()
    dp = [0] * (m + 1)
    last = [0] * (m + 1)
    for _ in range(n):
        s = sint()
        for i in range(s):
            x, y = mint()
            for j in range(m, x - 1, -1):
                dp[j] = max(dp[j], last[j - x] + y)
        last = dp.copy()
    print(dp[-1])


if __name__ == '__main__':
    solve()