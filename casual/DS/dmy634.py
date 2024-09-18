import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from math import inf


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

class Fenwick:
    
    def __init__(self, n):
        self.n = n
        self.a = [0] * (n + 1)
    
    
    def add(self, x, v):
        i = x + 1
        while i <= self.n:
            self.a[i] += v
            i += i & -i
    
    
    def sum(self, x):
        i = x + 1
        s = 0
        while i:
            s += self.a[i]
            i &= i - 1
        return s
    
    
    def rangeSum(self, l, r):
        return self.a[r] - self.a[l - 1]


def solve() -> None:
    n, q = mint()
    a = ints()
    tr = Fenwick(n)
    for i, x in enumerate(a):
        tr.add(i, x)
    
    for i in range(q):
        ops = ints()
        if ops[0] == 1:
            tr.add(ops[1] - 1, ops[2] - a[ops[1] - 1])
            a[ops[1] - 1] = ops[2]
        else:
            print(tr.sum(ops[1] - 1))


if __name__ == '__main__':
    solve()