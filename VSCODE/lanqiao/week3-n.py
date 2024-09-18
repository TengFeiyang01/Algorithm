import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from math import inf
from bisect import *


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

class Fenwick:

    def __init__(self, n) -> None:
        self.n = n
        self.tr = [0 for _ in range(n + 1)]

    def add(self, i, x):
        i += 1
        while i <= self.n:
            self.tr[i] += x
            i += i & -i
    
    def sum(self, i):
        i += 1
        ans = 0
        while i > 0:
            ans += self.tr[i]
            i &= i - 1
        return ans
    
    def rangeSum(self, l, r):
        return self.sum(r) - self.sum(l - 1)


def solve() -> None:
    n = sint()
    a = ints()
    b = a[:].sort()

    tr = Fenwick(n)

    for x in b[::-1]:
        x = bisect_left(b, x)
        ans += tr.sum(x)
        tr.add(x, 1)
    print(ans)

if __name__ == '__main__':
    solve()