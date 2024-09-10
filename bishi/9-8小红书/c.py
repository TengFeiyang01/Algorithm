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


class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n
        self.n = n
        self.setCount = n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        x, y = self.find(x), self.find(y)
        if x == y:
            return False
        if self.size[x] < self.size[y]:
            x, y = y, x
        self.parent[y] = x
        self.size[x] += self.size[y]
        self.setCount -= 1
        return True

    def connected(self, x, y):
        x, y = self.find(x), self.find(y)
        return x == y

def solve() -> None:
    n, m = map(int, input().split())
    
    uf = DSU((n + 2) * (m + 2))
    
    for i in range(1, n+2):
        uf.union(0, i * (m + 2))
    for i in range(0, m+2):
        uf.union(0, i)
    for i in range(0, m+2):
        uf.union(0, (n + 1) * (m + 2) + i)
    for i in range(0, n+2):
        uf.union(0, i * (m + 2) + (m + 1))
        
        
    s = [input() for _ in range(n)]
    for i, t in enumerate(s, 1):
        for j, c in enumerate(t, 1):
            if c == 'L':
                uf.union(i * (m + 2) + j, i * (m + 2) + j - 1)
            elif c == 'R':
                uf.union(i * (m + 2) + j, i * (m + 2) + j + 1)
            elif c == 'U':
                uf.union(i * (m + 2) + j, (i - 1) * (m + 2) + j)
            else:
                uf.union(i * (m + 2) + j, (i + 1) * (m + 2) + j)
    print((n + 2) * (m + 2) - uf.size[0])


if __name__ == '__main__':
    solve()