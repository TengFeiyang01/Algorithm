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
    w = list(map(int, input().split()))
    a = [list(map(int, input().split())) for _ in range(n)]
    ans = 0
    
    for i in range(1, 1 << n):
        res = 0
        for j in range(n):
            if i >> j & 1:
                res += w[j]
                for k in range(n):
                    if j != k:
                       if i >> j & 1 and i >> k & 1:
                           res += a[j][k]
        ans = max(ans, res)
    print(ans)

if __name__ == '__main__':
    solve()