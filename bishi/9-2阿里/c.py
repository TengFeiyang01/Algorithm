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

pri = []
not_prime = [False] * (1000002)
min_p = [0] * (1000002)

def pre(n):
    for i in range(2, n + 1):
        if not not_prime[i]:
            min_p[i] = i
            pri.append(i)
        for pri_j in pri:
            if i * pri_j > n:
                break
            not_prime[i * pri_j] = True
            min_p[i * pri_j] = pri_j
            if i % pri_j == 0:
                break

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
    n = int(input())
    pre(1000000)
    base = 1000000
    uf = DSU(2000001)
    for j in range(1, n + 1):
        t = list(map(int, input().split()))
        for i in range(1, t[0]+1):
            if min_p[t[i]] == t[i]:
                uf.union(j + base, min_p[t[i]])
    
    q = int(input())
    for i in range(q):
        x, y = map(int, input().split())
        print("YES" if uf.connected(x + base, y + base) else "NO")

if __name__ == '__main__':
    solve()