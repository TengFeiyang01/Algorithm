import sys

sys.setrecursionlimit(1000000)

input = lambda: sys.stdin.readline().rstrip()

from math import ceil, sqrt


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
    a = []
    for i in range(n):
        l, r = map(int, input().split())
        a.append((l, r))
    

    def check(x):
        uf = DSU(n)
        for i in range(n):
            for j in range(i + 1, n):
                if 4 * x * x >= (a[i][1] - a[j][1]) ** 2 + (a[i][0] - a[j][0]) ** 2:
                    uf.union(i, j)
        return uf.setCount == 1
    
    
    l, r = 0, 10**13
    while l < r:
        mid = l + r >> 1
        if check(mid):
            r = mid
        else:
            l = mid + 1
    print(l)
    


if __name__ == '__main__':
    solve()