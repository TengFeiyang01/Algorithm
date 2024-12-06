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
    n, l, r = map(int, input().split())
    a = list(map(int, input().split()))
    for i in range(1, n):
        x, y = a[i-1], a[i]
        if x < y:
            l = x
        else:
            r = x
        if l > r:
            print(-1)
            return
    if l < a[-1] < r and r - l > 2:
        print(r - l - 2)
    else:
        print(-1)

if __name__ == '__main__':
    solve()