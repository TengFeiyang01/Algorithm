#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    std::vector<int> dep(n);
    const int logn = std::__lg(n);

    std::vector p(logn + 1, std::vector(n, -1));
    std::vector sum(30, std::vector<int>(n));
    
    auto dfs = [&](auto self, int x) -> void {
        for (int i = 0; (2 << i) <= dep[x]; i++) {
            p[i + 1][x] = p[i][p[i][x]];
        }
        for (int i = 0; i < 30; i++) {
            sum[i][x] += a[x] >> i & 1;
        }
        for (auto y : adj[x]) {
            if (y == p[0][x]) {
                continue;
            }
            p[0][y] = x;
            dep[y] = dep[x] + 1;
            for (int i = 0; i < 30; i++) {
                sum[i][y] += sum[i][x];
            }
            self(self, y);
        }
    };
    dfs(dfs, 0);
    
    auto lca = [&](int x, int y) {
        if (dep[x] < dep[y]) {
            std::swap(x, y);
        }
        for (int i = logn; i >= 0; i--) {
            if (dep[x] - (1 << i) >= dep[y]) {
                x = p[i][x];
            }
        }
        for (int i = logn; i >= 0; i--) {
            if (p[i][x] != p[i][y]) {
                x = p[i][x];
                y = p[i][y];
            }
        }
        if (x != y) {
            x = p[0][x];
        }
        return x;
    };
    
    int q;
    std::cin >> q;
    
    while (q--) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        
        int l = lca(x, y);
        
        int d = dep[x] + dep[y] - dep[l] * 2 + 1;
        
        auto get = [&](int x, int y, int i) {
            int tot = sum[i][x] + sum[i][y] - sum[i][l];
            if (l) {
                tot -= sum[i][p[0][l]];
            }
            if (tot == 0) {
                return d;
            }
            int res = 0;
            for (int j = logn; j >= 0; j--) {
                if (dep[x] - (1 << j) >= dep[l] && sum[i][x] == sum[i][p[j][x]]) {
                    x = p[j][x];
                    res += 1 << j;
                }
            }
            if (a[x] >> i & 1) {
                return res;
            }
            res = d - 1;
            for (int j = logn; j >= 0; j--) {
                if (dep[y] - (1 << j) >= dep[x] && sum[i][x] < sum[i][p[j][y]]) {
                    y = p[j][y];
                    res -= 1 << j;
                }
            }
            return res;
        };
        
        std::vector<std::pair<int, int>> a;
        for (int i = 0; i < 30; i++) {
            a.emplace_back(get(x, y, i), 1);
        }
        int res = 30;
        int ans = 0;
        for (int i = 0; i < 30; i++) {
            a.emplace_back(d - get(y, x, i), -1);
        }
        std::sort(a.begin(), a.end());
        int lst = 0;
        for (auto [u, v] : a) {
            if (u > lst) {
                ans = std::max(ans, res);
            }
            lst = u;
            res += v;
        }
        if (d > lst) {
            ans = std::max(ans, res);
        }
        std::cout << ans << " \n"[q == 0];
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