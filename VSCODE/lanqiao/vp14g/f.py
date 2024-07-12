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

class DSU:
    def __init__(self, n):
        self.fa = list(range(n))
        self.size = [1] * n
        self.n = n
        self.setCount = n
        
    def find(self, x):
        if x != self.fa[x]:
            self.fa[x] = self.find(self.fa[x])
        return self.fa[x]   
    
    
    def union(self, x, y):
        x, y = self.find(x), self.find(y)
        if x == y: return False
        if self.size[x] < self.size[y]:
            x, y = y, x
        self.fa[y] = x
        self.size[x] += self.size[y]
        self.setCount -= 1
        return True

    
    def connected(self, x, y):
        x, y = self.find(x), self.find(y)
        return x == y

def zfunc(s):
    n = len(s)
    z = [0] * n
    z[0] = n
    l, r = 0, 0
    for i in range(1, n):
        # ...l..i..|..r
        #       z[i-l]    
        if i <= r and z[i - l] < r - i + 1:
            z[i] = z[i - l]
        else:
            z[i] = max(0, r - i + 1)
            while i + z[i] < n and s[z[i]] == s[i + z[i]]:
                z[i] += 1
            if i + z[i] - 1 > r:
                l = i
                r = i + z[i] - 1
               
               
               
               
class Factorial:
    def __init__(self, N, mod):
        N += 1
        self.mod = mod
        self.f = [1] * N
        self.g = [1] * N
        for i in range(1, N):
            self.f[i] = self.f[i - 1] * i % self.mod
        self.g[-1] = pow(self.f[-1], mod-2, mod)
        for i in range(N - 2, -1, -1):
            self.g[i] = self.g[i + 1] * (i + 1) % self.mod 
            
    
    def fac(self, n):
        return self.f[n]

    def fac_inv(self, n):
        return self.g[n]

    def comb(self, n, m):
        if n < m or m < 0 or n < 0: return 0
        return self.f[n] * self.g[m] % self.mod * self.g[n - m] % self.mod
    
    def permu(self, n, m):
        if n < m or m < 0 or n < 0: return 0
        return self.f[n] * self.g[n - m] % self.mod

    

def solve() -> None:


if __name__ == '__main__':
    solve()