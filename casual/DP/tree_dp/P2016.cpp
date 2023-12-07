#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

// 最小点覆盖
void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n; ++i) {
    	int u, x;
    	std::cin >> x >> x;
    	for (int j = 0; j < x; ++j) {
    		int v;
    		std::cin >> v;
    		adj[i].push_back(v);
    	}
    }

    std::vector<std::array<int, 2>> dp(n);
    std::function<void(int, int)> dfs = [&](int u, int fa) {
    	dp[u][1] = 1;
    	for (auto v : adj[u]) {
    		if (v != fa) {
    			dfs(v, u);
    			dp[u][1] += std::min(dp[v][1], dp[v][0]);
    			dp[u][0] += dp[v][1];
    		}
    	}
    };

    dfs(0, -1);
    std::cout << std::min(dp[0][0], dp[0][1]);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
