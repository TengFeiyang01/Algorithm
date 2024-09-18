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
from math import inf


def solve() -> None:
    n = sint()
    a = ints()
    z = 0
    neg, mxI = 0, -1
    for i, x in enumerate(a):
        if x < 0:
            neg += 1
            if mxI < 0 or x > a[mxI]:
                mxI = i
        elif x == 0:
            z += 1
    if n == 1:
        print(a[0])
        return
    if z == n or z == n - 1 and neg == 1:
        print(0)
        return
    for i, x in enumerate(a):
        if x != 0 and (neg % 2 == 0 or i != mxI):
            print(x, end=' ')

if __name__ == '__main__':
    solve()