#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, s;
    std::cin >> n >> s;
    std::vector<i64> dist(n);
    std::vector<std::vector<std::pair<int, i64>>> adj(n);
    for (int i = 1; i < n; ++i) {
    	int u, v, w;
    	std::cin >> u >> v >> w;
    	--u, --v;
    	adj[u].emplace_back(v, w);
    	adj[v].emplace_back(u, w);
    }
    // dp[i] 以i为根的子树的所有结点变为相同值所需要的最小的操作数
    i64 ans = 0;
    std::function<void(int, int)> dfs = [&](int u, int fa) {
    	for (auto [v, w] : adj[u]) {
    		if (v != fa) {
    			dfs(v, u);
    			dist[u] = std::max(dist[u], dist[v] + w);
    		}
    	}
    	for (auto [v, w] : adj[u]) {
    		if (v != fa) {
    			ans += dist[u] - (dist[v] + w);
    		}
    	}
    };
    dfs(--s, -1);
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
