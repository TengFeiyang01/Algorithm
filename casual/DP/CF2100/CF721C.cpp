#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, T;
    std::cin >> n >> m >> T;
    std::vector dp(n, std::vector<i64>(n + 1, inf));
    std::vector pre(n, std::vector<short>(n + 1, 0));
    std::vector<std::array<int, 3>> edges;

    for (int i = 0; i < m; ++i) {
    	int u, v, w;
    	std::cin >> u >> v >> w;
    	edges.push_back({u - 1, v - 1, w});
    }
    dp[n - 1][0] = 0;
    for (int j = 1; j <= n; ++j) {
    	for (auto [u, v, w] : edges) {
    		if (dp[v][j - 1] + w < dp[u][j]) {
    			dp[u][j] = dp[v][j - 1] + w;
    			pre[u][j] = v;
    		}
    	}
    }
    int ans = 0;
    for (int j = 1; j <= n; ++j) {
    	if (dp[0][j] <= T) {
    		ans = j;
    	}
    }
    std::cout << ans + 1 << "\n";
    std::vector<int> path;
    int u = 0;
    while (u != n - 1) {
    	path.push_back(u);
    	u = pre[u][ans--];
    }
    for (auto x : path) {
    	std::cout << x + 1 << " ";
    }
    std::cout << n;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
