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
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    # 选一个最小的区间
    small = []
    big = []
    mx = 0
    idx = -1
    t = 0
    mns = inf
    l, r = -1, -1
    for i in range(n):
        t += a[i]
        if t - mx < mns:
            mns = t - mx
            l, r = idx + 1, i
        if t > mx:
            idx = n
            mx = t
    small = [l, r]
    
    mn = 0
    idx = -1
    t = 0
    mxs = -inf
    l, r = -1, -1
    for i in range(n):
        t += a[i]
        if t - mn > mxs:
            mxs = t - mn
            l, r = idx + 1, i
        if t < mn:
            mn = t
            idx = i
    big = [l, r]
    
    if k > 0:
        l, r = big
        for i in range(l, r+1):
            a[i] *= k
    else:
        l, r = small
        for i in range(l, r+1):
            a[i] *= k
    if k > 0:
        l, r = small
        for i in range(l, r+1):
            a[i] *= k
    else:
        l, r = big
        for i in range(l, r+1):
            a[i] *= k
    
    print(sum(a))
    
if __name__ == '__main__':
    solve()