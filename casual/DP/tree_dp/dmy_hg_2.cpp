#include <bits/stdc++.h>

using i64 = long long;
const i64 inf = 1LL << 60;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> g[n], d(n);
    d[0] = 1;
    for (int i = 1; i < n; ++i) {
        int fa;
    	std::cin >> fa;
        fa--;
    	g[fa].push_back(i);
    	d[i] = d[fa] + 1;
    }

    std::vector<std::array<int, 2>> path[n];
    for (int i = 0; i < m; ++i) {
    	int u, v, w;
    	std::cin >> u >> v >> w;
        --u, --v;
    	path[v].push_back({u, w});
    }
    
    std::vector<std::vector<i64>> dp(n, std::vector<i64>(n + 2));

    std::vector<i64> sufa(n + 1), sufb(n + 1);

    std::function<void(int)> dfs = [&](int u) {

        // std::fill(dp[u].begin() + 1, dp[u].begin() + d[u] + 1, inf);
        for (int i = 1; i <= d[u]; ++i) dp[u][i] = inf;

        for (auto p: path[u]) {
            dp[u][d[p[0]]] = std::min(dp[u][d[p[0]]], i64(p[1]));
        }

    	for (auto v : g[u]) {
    		dfs(v);
            /*
            暴力
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= d[v]; ++j)
                    tmp[std::min(i, j)] = std::min(dp[v][j] + dp[u][i], tmp[std::min(i, j)]);
    	   */
            auto &a = dp[u], &b = dp[v];
            int len = d[v];
            sufa[len + 1] = inf;
            sufb[len + 1] = inf;
            for (int i = len; i >= 1; --i) {
                sufa[i] = std::min(sufa[i + 1], a[i]);
                sufb[i] = std::min(sufb[i + 1], b[i]);
            }
            for (int i = 1; i <= len; ++i) {
                a[i] = std::min(a[i] + sufb[i], b[i] + sufa[i]);
            }
        }
    };
    dfs(0);
    std::cout << (dp[0][1] >= inf / 2 ? -1 : dp[0][1]);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
