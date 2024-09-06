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


# 左闭右闭
class FenWick:
    def __init__(self, n: int):
        self.n = n
        self.tr = [0 for _ in range(n + 1)]

    def sum(self, i: int):
        i += 1
        s = 0
        while i >= 1:
            s += self.tr[i]
            i &= i - 1
        return s

    def rangeSum(self, l: int, r: int):
        return self.sum(r) - self.sum(l - 1)

    def add(self, i: int, val: int):
        i += 1
        while i <= self.n:
            self.tr[i] += val
            i += i & -i

def solve() -> None:
    n = int(input())
    
    dp = FenWick(n + 1)
    dp.add(n, 1)
    
    for i in range(n-1, 0, -1):
        cur = dp.rangeSum(i+1, n)
        # suf = 0
        p = 2
        while i * p <= n:
            cur += dp.rangeSum(i*p, min(n, i*(p+1)-1))
            p += 1
        dp.add(i, cur)
    for i in range(1, n + 1):
        print(i, dp.rangeSum(i, i))
    print(dp.sum(1))

if __name__ == '__main__':
    solve()