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
# 51476->51646->55146->55414->55431

def solve() -> None:
    s = list(map(int, list(input())))
    n = len(s)
    for i in range(n):
        p = 0
        for j in range(1, 10):
            if i + j < n and s[i + j] - j > s[i + p] - p:
                p = j
        if p:
            mx = s[i + p] - p
            for j in range(p, 0, -1):
                s[i + j], s[i + j - 1] = s[i + j - 1], s[i + j]
            s[i] = mx
    print(''.join(map(str, s)))

if __name__ == '__main__':
    for _ in range(int(input())):
        solve()