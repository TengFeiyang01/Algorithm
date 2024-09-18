# D:\Algorithm\bishi\9-14小红书\a3.py 2024-09-14 by ytf
import sys

sys.setrecursionlimit(100000)

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
    n, k = mint()
    x = ints()
    y = ints()
    ans = 0
    uf = DSU(n)
    for i in range(n):
        for j in range(n):
            if abs(x[i] - x[j]) + abs(y[i] - y[j]) <= k:
                uf.union(i, j)
    print(max(uf.size[i] for i in range(n)))
                

if __name__ == '__main__':
    solve()