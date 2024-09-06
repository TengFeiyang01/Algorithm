from math import *

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
    a = list(map(int, input().split()))
    dp = [inf] * n
    dp[0] = 0
    edge = []
    for i in range(n):
        for j in range(i + 1, n):
            edge.append((lcm(a[i], a[j]), i, j))
            
    edge.sort()
    uf = DSU(n)
    ans = 0
    for w, x, y in edge:
        if not uf.connected(x, y):
            uf.union(x, y)
            ans += w
    print(ans + sum(a))    

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solve()