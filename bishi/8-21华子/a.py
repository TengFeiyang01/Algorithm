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
    m, n = map(int, input().split())
    t = []
    for i in range(n):
        a, b = map(int, input().split())
        t = t + [b] * min(a, m)
        t.sort()
        if len(t) > m:
            t = t[-m:]
        for x in t[::-1]:
            print(x, end='')
        if i != n - 1:
            print()
        

if __name__ == '__main__':
    solve()