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
        self.siz = [1] * n
        self.n = n
        self.setCount = n

    def find(self, x):
        while x != self.parent[x]:
            x = self.parent[x] = self.parent[self.parent[x]]
        return x

    def union(self, x, y):
        x, y = self.find(x), self.find(y)
        if x == y:
            return False
        self.parent[y] = x
        self.siz[x] += self.siz[y]
        self.setCount -= 1
        return True

    def connected(self, x, y):
        x, y = self.find(x), self.find(y)
        return x == y
    

    def size(self, x):
        return self.siz[self.find(x)]


def solve() -> None:
    n, q = mint()
    cnt = [1] * n
    col = list(range(n))
    dsu = DSU(n)
    for _ in range(q):
        ops = ints()
        if ops[0] == 1:
            x, c = ops[1], ops[2]
            x, c = x - 1, c - 1
            x = dsu.find(x)
            cnt[col[x]] -= dsu.size(x)
            col[x] = c
            cnt[c] += dsu.size(x)
            if x and col[dsu.find(x - 1)] == c:
                dsu.union(x - 1, x)
                x = dsu.find(x)
            if x + dsu.size(x) < n and col[x + dsu.size(x)] == c:
                dsu.union(x, x + dsu.size(x))
        elif ops[0] == 2:
            x = ops[1]
            print(cnt[x - 1])


if __name__ == '__main__':
    solve()