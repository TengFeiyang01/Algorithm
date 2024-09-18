#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector dp(n, std::vector(m + 1, -inf));
    std::vector<std::vector<std::array<int, 2>>> adj(n);
    for (int i = 0; i < n - m; ++i) {
    	int k, v, w;
    	std::cin >> k;
    	for (int j = 0; j < k; ++j) {
    		std::cin >> v >> w;
    		adj[i].push_back({v - 1, w});
    	}
    }
    std::vector<int> a(n);
    for (int i = n - m; i < n; ++i) {
    	std::cin >> a[i];
    }

    std::function<int(int)> dfs = [&](int u) {
    	dp[u][0] = 0;
    	if (u >= n - m) {
    		dp[u][1] = a[u];
    		return 1;
    	}
    	int sum = 0;
    	for (auto [v, w] : adj[u]) {
    		int sv = dfs(v);
    		sum += sv;
    		for (int j = sum; j >= 0; --j) {
    			for (int k = 0; k <= sv and k <= j; ++k) {
    				dp[u][j] = std::max(dp[u][j], dp[u][j - k] + dp[v][k] - w);
    			}
    		}
    	}
    	return sum;
    };
    dfs(0);
    for (int i = m; i >= 0; --i) {
    	if (dp[0][i] >= 0) {
    		std::cout << i << "\n";
    		return;
    	} 
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
