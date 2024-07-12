#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::array<int, 2>>> adj(n);
    for (int i = 1; i < n; ++i) {
    	int u, v, w;
    	std::cin >> u >> v >> w;
    	--u, --v;
    	adj[u].push_back({v, w});
    	adj[v].push_back({u, w});
    }

    std::vector dp(n, std::vector(n, 0));
    std::vector<int> siz(n);

    std::function<void(int, int)> dfs = [&](int u, int fa) ->void {
    	for (auto [v, w] : adj[u]) {
    		if (v == fa) continue;
    		dfs(v, u);
    		siz[u] += siz[v] + 1;
    		for (int i = std::min(siz[u], m); i > 0; --i) {
    			for (int j = std::min(siz[v], i - 1); j >= 0; --j) {
    				dp[u][i] = std::max(dp[u][i], dp[u][i - j - 1] + dp[v][j] + w);
    			}
    		}
    	}
    };
    dfs(0, -1);
    std::cout << dp[0][m] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
