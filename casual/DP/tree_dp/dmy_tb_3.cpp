#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> adj[n + 1], c(n + 1), w(n + 1);
    for (int i = 2; i <= n; ++i) {
        int fa;
        std::cin >> fa;
        adj[fa].emplace_back(i);
    }

    for (int i = 1; i <= n; ++i) std::cin >> c[i];
    for (int i = 1; i <= n; ++i) std::cin >> w[i];
    
    std::vector<int> l(n + 1), r(n + 1), id(n + 1);
    std::vector<std::vector<i64>> dp(n + 2, std::vector<i64>(m + 1));
    //f[i][j] = max(f[ri][j], f[i + 1][j - w] + v);
    int tot = 0;
    
    std::function<void(int)> dfs = [&](int u) {
        l[u] = ++tot;
        id[tot] = u;
        for (auto &v : adj[u]) dfs(v);
        r[u] = tot;
    };
    
    dfs(1);
    for (int i = 1; i <= m; ++i) dp[n + 1][i] = -1e16;
    for (int i = n; i >= 1; --i) {
        int u = id[i];
        for (int j = 0; j <= m; ++j) {
            dp[i][j] = dp[r[u] + 1][j];
            if (j >= w[u])
                dp[i][j] = std::max(dp[i][j], dp[i + 1][j - w[u]] + c[u]);
        }
    }
    for (auto x : dp[1]) std::cout << std::max(x, 0LL) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}