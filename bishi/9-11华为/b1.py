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
    a = [ints() for i in range(n)]
    a.sort(key=lambda x: (-x[0], -x[1]))
    dp = [x[2] for x in a]
    for i in range(n):
        for j in range(i):
            if all(x < y for x, y in zip(a[i], a[j])):
                dp[i] = max(dp[i], dp[j] + a[i][2])
    print(max(dp))

if __name__ == '__main__':
    solve()