#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, q;
    std::cin>> n >> q;
    m = 100;
    std::vector<int> c(n), sz(n);
    std::vector<int> adj[n];
    for (int i = 1; i < n; ++i) {
        int fa;
        std::cin >> fa;
        adj[fa - 1].push_back(i);
    }
    for (int i = 0; i < n; ++i) std::cin >> c[i];

    std::vector<std::vector<i64>> dp(n, std::vector<i64>(m + 1, -1e18));

    std::function<void(int)> dfs = [&](int u) {
        sz[u] = 1;
        dp[u][0] = 0;
        dp[u][1] = c[u];
        for (auto &v : adj[u]) {
            dfs(v);
            for (int i = sz[u]; i > 0; --i) {
                for (int j = std::min(m - i, sz[v]); j > 0; --j) {
                    dp[u][i + j] = std::max(dp[u][i + j], dp[u][i] + dp[v][j]);
                }
            }
            // dp[u] = tmp;
            sz[u] += sz[v];
        }
        if (sz[u] > m) sz[u] = m;
    };
    dfs(0);
    while (q--) {
        int x, y;
        std::cin >> x >> y;
        x--, y;
        std::cout << dp[x][y] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
