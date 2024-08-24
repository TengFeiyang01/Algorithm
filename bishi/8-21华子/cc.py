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
    g = [[0] * (n + 1) for _ in range(n)]
    for i in range(n):
        a = list(map(int, input().split()))
        for x in a[1:]:
            g[i + 1][x] = 1
    ans = 0
    for i in range(1, n+1):
        for j in range(i + 1, n + 1):
            if g[i][j] and g[j][i]:
                ans += 1
    print(ans) 
    

if __name__ == '__main__':
    solve()