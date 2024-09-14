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

from math import sqrt, ceil
def solve() -> None:
    n = int(input())
    a = []
    for i in range(n):
        x, y = map(int, input().split())
        a.append((x, y))
    
    def get(i, j):
        d = (a[i][0] - a[j][0]) * (a[i][0] - a[j][0]) + (a[i][1] - a[j][1]) * (a[i][1] - a[j][1])
        s = int(sqrt(d))
        return (s + 1) // 2 if s * s == d else (s // 2 + 1)
    
    adj = []
    for i in range(n):
        for j in range(i + 1, n):
            adj.append((get(i, j), i, j))
    adj.sort()
    uf = DSU(n)
    ans = 0
    for d, x, y in adj:
        if not uf.connected(x, y):
            uf.union(x, y)
            ans = d

    print(ans)



if __name__ == '__main__':
    solve()