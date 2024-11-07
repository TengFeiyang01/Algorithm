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
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = [list(map(int, input().split())) for _ in range(m)]
    dp = [0] * (n + 1)
    c = []
    b.sort()
    a.sort()
    i, j = 0, 0
    for x in a:
        while j < m and b[j][0] <= x <= b[j][1]:
            j += 1
        while i < m and b[i][1] < x:
            i += 1
        
    

if __name__ == '__main__':
    solve()