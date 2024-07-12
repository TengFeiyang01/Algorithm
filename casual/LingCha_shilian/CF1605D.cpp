#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    std::vector<int> c(n);
    auto dfs = [&](auto self, int x, int p) -> void {
        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }
            c[y] = c[x] ^ 1;
            self(self, y, x);
        }
    };
    dfs(dfs, 0, -1);
    
    int c0 = std::count(c.begin(), c.end(), 0);
    int c1 = n - c0;
    
    int i0 = 0, i1 = 0;
    std::vector<int> p(n);
    for (int t = std::__lg(n); t >= 0; t--) {
    	// 当前这一位可以分配的数的个数
        int v = std::min(1 << t, n - (1 << t) + 1);
        if (v <= c0) {
            c0 -= v;
            for (int j = 0; j < v; j++) {
                while (c[i0] != 0) {
                    i0++;
                }
                p[i0] = (1 << t) + j;
                i0++;
            }
        } else {
            c1 -= v;
            for (int j = 0; j < v; j++) {
                while (c[i1] != 1) {
                    i1++;
                }
                p[i1] = (1 << t) + j;
                i1++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << p[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}