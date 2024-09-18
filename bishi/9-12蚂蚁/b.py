import sys
from math import gcd
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
    n, m, k = map(int, input().split())
    a = [ints() for _ in range(n)]
    uf = DSU(m * n)
    for i in range(n):
        for j in range(m):
            if i and a[i - 1][j] != 0 and a[i][j] != 0 and k % gcd(a[i][j], a[i - 1][j]) == 0:
                uf.union(i * m + j, (i - 1) * m + j)
            if i:
                if a[i][j] == 0 and a[i - 1][j] != 0 and  k % a[i - 1][j] == 0:
                    uf.union(i * m + j, (i - 1) * m + j)
                if a[i - 1][j] == 0 and a[i][j] != 0 and k % a[i][j] == 0:
                    uf.union(i * m + j, (i - 1) * m + j)


            if j and a[i][j] != 0 and a[i][j - 1] != 0 and k % gcd(a[i][j], a[i][j - 1]) == 0:
                uf.union(i * m + j, i * m + j - 1)
            if j:
                if a[i][j] == 0 and a[i][j - 1] != 0 and k % a[i][j - 1] == 0:
                    uf.union(i * m + j, i * m + j - 1)
                if a[i][j - 1] == 0 and a[i][j] != 0 and k % a[i][j] == 0:
                    uf.union(i * m + j, i * m + j - 1)


    mod = 1000000007
    tot = n * m
    q = int(input())
    for i in range(q):
        x, y = mint()
        x -= 1
        y -= 1
        p = x * m + y
        now = uf.size[uf.find(p)]
        other = tot - now
        g = gcd(other, tot)
        print(other // g * pow(tot // g, mod-2, mod) % mod)

if __name__ == '__main__':
    solve()