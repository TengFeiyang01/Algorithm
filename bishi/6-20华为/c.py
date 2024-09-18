import sys
from math import inf
from collections import deque

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
    sx, sy = mint()
    n, m = mint()
    g = [ints() for _ in range(n)]
    
    get = lambda x, y : x * m + y
    
    uf = DSU(n * m)
    st = set()
    for i in range(n):
        for j in range(m):
            if g[i][j] == 1:
                if i and g[i - 1][j]:
                    uf.union(get(i, j), get(i - 1, j))
                if j and g[i][j - 1]:
                    uf.union(get(i, j), get(i, j - 1))
    
    for i in range(n):
        for j in range(m):
            if g[i][j]:
                st.add(uf.find(get(i, j)))
    if len(st) == 1:
        print(-1)
        return
    
    
    dp = [[inf] * m for _ in range(n)]
    
    q = deque()
    for i in range(n):
        for j in range(m):
            if g[i][j] and uf.connected(get(i, j), get(sx, sy)):
                q.append((i, j))
                dp[i][j] = 0

    while q:
        i, j = q.popleft()
        if g[i][j] and not uf.connected(get(i, j), get(sx, sy)):
            print(dp[i][j]-1)
            return
        for x, y in (i + 1, j), (i, j + 1), (i - 1, j), (i, j - 1):
            if 0 <= x < n and 0 <= y < m and dp[x][y] > dp[i][j] + 1:
                dp[x][y] = dp[i][j] + 1
                q.append((x, y))    
    

if __name__ == '__main__':
    solve()