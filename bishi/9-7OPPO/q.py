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
    n = int(input())
    a = ints()
    ans = inf
    cur = 0
    for i in range(n):
        if a[i] % 2:
           cur += a[i] + 1
    ans = min(ans, cur)
    cur = 0
    for i in range(n):
        if a[i] % 2 == 0:
           cur += a[i] + 1
    ans = min(ans, cur)
    print(ans)

if __name__ == '__main__':
    solve()