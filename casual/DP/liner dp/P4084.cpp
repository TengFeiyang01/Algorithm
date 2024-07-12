#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> adj(n);
    std::vector<int> color(n);
    std::vector dp(n, std::vector<i64>(3, 1));
    for (int i = 1; i < n; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    for (int i = 0; i < k; ++i) {
    	int x, c;
    	std::cin >> x >> c;
    	color[x - 1] = c - 1;
    	for (int i = 0; i < 3; ++i) {
    		if (c - 1 != i) {
    			dp[x - 1][i] = 0;
    		}
    	}
    }
    const int mod = 1000000007;
    std::function<void(int, int)> dfs = [&](int u, int fa) {
    	for (auto v : adj[u]) {
    		if (v != fa) {
    			dfs(v, u);
    			dp[u][0] = dp[u][0] * (dp[v][1] + dp[v][2]) % mod;
    			dp[u][1] = dp[u][1] * (dp[v][0] + dp[v][2]) % mod;
    			dp[u][2] = dp[u][2] * (dp[v][0] + dp[v][1]) % mod;
    		}
    	}
    };
    dfs(0, -1);
    std::cout << (dp[0][0] + dp[0][1] + dp[0][2]) % mod << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
