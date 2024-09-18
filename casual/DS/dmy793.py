import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache

from collections import*
from math import inf


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

class DSU:
    def __init__(self, n):
        self.p = list(range(n))
        self.n = n
        self.setCount = n

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, x, y):
        x, y = self.find(x), self.find(y)
        if x == y:
            return False
        self.p[x] = y
        self.setCount -= 1
        return True

    def connected(self, x, y):
        x, y = self.find(x), self.find(y)
        return x == y


def solve() -> None:
    n, m = mint()
    edges = []
    for i in range(n - 1):
        x, y, w = mint()
        edges.append((w, x - 1, y - 1))
    queries = defaultdict(list)
    vec = defaultdict(list)
    
    bel = [0] * n
    for i in range(n):
        vec[i].append(i)
        bel[i] = i
        
    for i in range(m):
        x, y = mint()
        x, y = x - 1, y - 1
        queries[x].append((y, i))
        queries[y].append((x, i))
        
    ans = [0] * m
    edges.sort(reverse=True)
    uf = DSU(n)
    
    for p, x, y in edges:
        u, v = uf.find(x), uf.find(y)            
        if len(vec[u]) > len(vec[v]):
            u, v = v, u
            
        for w, id in queries[u]:
            if ans[id] != 0: continue
            if bel[w] == v:
                ans[id] = p
            else:
                queries[v].append((w, id))
        queries[u].clear()
        for w in vec[u]:
            vec[v].append(w)
            bel[w] = v
        vec[u].clear()
        uf.union(u, v)
        
    for x in ans:
        print(x)      
    

if __name__ == '__main__':
    solve()