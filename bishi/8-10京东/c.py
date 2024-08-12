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
    n = sint()
    a = [0] + ints()
    for i in range(1, n + 1):
        x, a[i] = a[i], 0
        while x:
            if x & 1:
                a[i] += 1
                x -= 1
            if x:
                a[i] += 1
            x >>= 1
        
    p, q = 0, 0
    
    for i in range(n, 0, -1):
        a[i] -= a[i - 1]
        if a[i] > 0:
            p += a[i]
        else:
            q -= a[i]
    print(max(p, q))
    
if __name__ == '__main__':
    _ = sint()
    for i in range(_):
        solve()