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
    a = list(map(int, list(input())))
    s = sum(a) % 9
    b = []
    for x in a:
        if x * x < 10 and x * x != x:
            b.append(x * x - x)
    b.sort()
    dp = [0] * 10
    dp[0] = 1
    for x in b:
        ndp = [0] * 10
        for i in range(10):
            if dp[i]:
                ndp[(i + x) % 9] = 1
                ndp[i] = 1
        dp = ndp
    if dp[(9 - s) % 9]:
        print("YES")
    else:
        print("NO")

if __name__ == '__main__':
    for _ in range(int(input())):
        solve()