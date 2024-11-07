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
    n = sint()
    a = ints()
    s = sum(a)
    if s % 3:
        print(0)
    else:
        m = s//3*2
        dp = [1] + [0] * m
        for x in a:
            for j in range(m, x-1,-1):
                dp[j] += dp[j - x]
                dp[j] %= (10**9+7)
    print(dp[-1])

if __name__ == '__main__':
    solve()