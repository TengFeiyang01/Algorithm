import math
from itertools import combinations

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0:
            return False
    return True

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

def solve():
    for n in range(100):
        uf = DSU(n + 1)
        graph = {i: set() for i in range(1, n + 1)}
        for i, j in combinations(range(1, n + 1), 2):
            if is_prime(gcd(i, j)):
                uf.union(i, j)
                graph[i].add(j)
                graph[j].add(i)
        print(uf.setCount-1, end=",")
    

solve()