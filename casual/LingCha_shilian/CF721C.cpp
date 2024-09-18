#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 inf = 1e15;

struct Edge {
    int u, v, w;
};


void solve() {
    int n, m, T;
    std::cin >> n >> m >> T;
    std::vector<Edge> edge(m);

    for (auto &[u, v, w] : edge) {
    	std::cin >> u >> v >> w;
    }
    std::vector dp(n + 1, std::vector<int>(n + 1, T + 1));
    std::vector from(n + 1, std::vector<short>(n + 1));
    dp[0][1] = 0;


    int ans = 0;
    for (int i = 1; i < n; ++i) {
    	for (auto [u, v, w] : edge) {
    		if (dp[i][v] > dp[i - 1][u] + w) {
    			dp[i][v] = dp[i - 1][u] + w;
    			from[i][v] = u;
    		}
    	}
        if (dp[i][n] <= T) {
            ans = i;
        }
    }

    std::cout << ans + 1 << "\n";
    std::vector<int> path(ans + 1);
    int v = n;
    for (int i = ans; i >= 0; --i) {
        path[i] = v;
        v = from[i][v];
    }
    for (int i = 0; i <= ans; ++i) {
        std::cout << path[i] << " ";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
