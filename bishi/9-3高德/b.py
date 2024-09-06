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
    s, t = input().split(',')
    n, m = len(s), len(t)
    f = [[0] * (m + 1) for _ in range(n + 1)]
    f[0] = list(range(m + 1))
    for i, x in enumerate(s):
        f[i + 1][0] = i + 1
        for j, y in enumerate(t):
            f[i + 1][j + 1] = f[i][j] if x == y else \
                              min(f[i][j + 1], f[i + 1][j], f[i][j]) + 1
    print(f[n][m])
                       

if __name__ == '__main__':
    solve()