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
    n, m = mint()
    a = [ints() for i in range(n)]
    
    lastRow = [-1] * n
    lastCol = [-1] * m

    uf = DSU(m * n)
    for i, row in enumerate(a):
        for j, x in enumerate(row):
            if x:
                for (nx, ny) in (i+1, j), (i-1,j), (i, j+1), (i, j-1):
                    if 0 <= nx < n and 0 <= ny < m and a[nx][ny]:
                        uf.union(i * m + j, nx * m + ny)

    print(max(uf.size))


if __name__ == '__main__':
    solve()


#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    double b;
    std::cin >> n >> b;
    std::vector<std::vector<double>> a(n, std::vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> a[i][j];
        }
    }

    if (n == 1) {
        std::cout << "kono jinsei, imi ga nai!\n";
        return;
    }
    std::vector<int> deg(n);
    for (int i = 0; i < n; ++i) {
        int x = -1;
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                if (x == -1 or a[i][j] > a[i][x]) {
                    x = j;
                }
            }
        }
        if (a[i][x] >= b) {
            deg[x]++;
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
