#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 inf = 1e18;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }

    std::vector<std::vector<i64>> dp(11, std::vector<i64>(n));
    std::vector<std::vector<int>> size(11, std::vector<int>(n));

    auto dfs = [&](auto &&self, int u, int fa, i64 d) -> void {
    	size[a[u]][u] = 1;
    	dp[a[u]][0] += d * a[u];
    	for (auto v : adj[u]) {
    		if (v != fa) {
    			self(self, v, u, d + 1);

    			for (int j = 1; j <= 10; ++j) {
    				size[j][u] += size[j][v];
    			}
    		}
    	}
    };

    std::vector<i64> ans(11, inf);
    // u->v f[v] = f[u] - size[v] * a[u] + (n - size[v]) * a[u]
    auto reroot = [&](auto &&self, int u, int fa) -> void {
    	for (int j = 1; j <= 10; ++j) {
    		ans[j] = std::min(ans[j], dp[j][u]);
    	}
    	for (auto v : adj[u]) {
    		if (v != fa) {
    			for (int j = 1; j <= 10; ++j) {
    				dp[j][v] = dp[j][u] + j * (size[j][0] - 2 * size[j][v]);
    			}
    			self(self, v, u);
    		}
    	}
    };

    dfs(dfs, 0, -1, 0);

    reroot(reroot, 0, -1);
    i64 res = 0;
    for (int i = 1; i <= 10; ++i) {
    	if (ans[i] != inf) {
    		res += ans[i];
    	}
    }
    std::cout << res << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
