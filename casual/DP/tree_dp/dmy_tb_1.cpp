#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 inf = 1e17;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n);
    std::vector<std::vector<i64>> f(n, std::vector<i64>(n + 1, -inf));

    for (int fa, i = 1; i < n; ++i) {
        std::cin >> fa;
        adj[fa - 1].push_back(i); 
    }
    
    std::vector<int> siz(n), a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::function<void(int)> dfs = [&](int u) {
        siz[u] = 1;
        f[u][0] = 0;
        f[u][1] = a[u];
        for (auto v : adj[u]) {
            dfs(v);
            // std::vector<i64> tmp(siz[u] + siz[v] + 1, -1e18);
            // for (int i = 1; i <= siz[u]; ++i) tmp[i] = f[u][i];
            // for (int i = 1; i <= siz[u]; ++i) {
            //     for (int j = 1; j <= siz[v]; ++j) {
            //         tmp[i + j] = std::max(tmp[i + j], f[u][i] + f[v][j]);
            //     }
            // }
            // f[u] = tmp;
            // 倒序遍历
            for (int i = siz[u]; i >= 1; --i) {
                for (int j = siz[v]; j >= 1; --j) {
                    f[u][j + i] = std::max(f[u][i + j], f[u][i] + f[v][j]);
                }
            }
            siz[u] += siz[v];
        }
    };
    dfs(0);
    
    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        --x;
        std::cout << f[x][y] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
