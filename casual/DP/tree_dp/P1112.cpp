#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }

    std::vector<std::vector<int>> adj(n);
    for (int i = 1, u, v; i < n; ++i) {
    	std::cin >> u >> v;
    	--u, --v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    std::vector<i64> dp(n);
    std::function<void(int, int)> dfs = [&](int u, int fa) {
    	dp[u] = a[u];
    	for (auto v : adj[u]) {
    		if (v != fa) {
    			dfs(v, u);
    			dp[u] += std::max(dp[v], 0ll);
    		}
    	}
    };
    dfs(0, -1);
    std::cout << std::ranges::max(dp);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
