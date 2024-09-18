import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from math import inf, sqrt


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

from collections import *

def solve() -> None:
    n = sint()
    s = input()
    adj = [[] for _ in range(n)]
    uf = DSU(n)
    ans = 0
    mod = 10 ** 9 + 7
    
    d = [defaultdict(int) for _ in range(n)]
    
    for i in range(n-1):
        u, v = mint()
        u, v = u-1, v-1
        if s[u] == 'R' and s[v] == 'R':
            uf.union(u, v)
        
    for i in range(n):
        fa = uf.find(i)
        if s[i] == 'W': continue
        x = i + 1
        for j in range(2, int(x**0.5)+1):
            while x % j == 0:
                x //= j
                d[fa][j] += 1
        if x != 1:
            d[fa][x] += 1
    # 2 3 4 | 5 6 7 
    st = set()
    for i in range(n):
        cur = 1
        fa = uf.find(i)
        if s[i] == 'R' and fa not in st:
            st.add(fa)
            for v in d[fa].values():
                cur = cur * (v + 1) % mod
            ans = (ans + cur) % mod
    print(ans)
        
        

if __name__ == '__main__':
    solve()