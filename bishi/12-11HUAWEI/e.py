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

def get(a):
    mx = a[0]
    s = a[0]
    l, r = 0, 0
    st = 0
    for i in range(1, len(a)):
        x = a[i]
        if s + x < x:
            st = i
        s = max(s + x, x)
        if s > mx:
            l, r = st, i
            mx = s
    return l, r, mx

def cakculateMaxQuality(impactFactor, ratings):
    ans = -inf
    n = len(ratings)
    _, _, mx = get(ratings)
    for i in range(n):
        ratings[i] *= -1
    ans = max(ans, mx * impactFactor)
    l, r, mx = get(ratings)
    for i in range(n):
        ratings[i] *= -1
    for i in range(l, r + 1):
        ratings[i] = (ratings[i] + impactFactor - 1) // impactFactor
    _, _, s = get(ratings)
    ans = max(ans, s)

    return ans

def solve() -> None:
    print(cakculateMaxQuality(sint(), ints()))

if __name__ == '__main__':
    solve()