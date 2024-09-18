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
    s = input()
    t = input()
    n, m = len(s), len(t)
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    ans = 1
    pos = 0
    for i in range(1, n+1):
        for j in range(1, m+1):
            if s[i - 1] == t[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
                if ans <= dp[i][j]:
                    ans = dp[i][j]
                    pos = i - ans
    print(s[pos:pos+ans])

if __name__ == '__main__':
    solve()