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
    t = sint()
    for i in range(t):
        m, n, c = mint()
        a = ints()
        dp = [1] + [0] * m
        for x in a:
            for j in range(m, x-1, -1):
                dp[j] |= dp[j - x]
        c = min(c, m)
        print("YES" if sum(dp[m - c:]) else "NO")

if __name__ == '__main__':
    solve()