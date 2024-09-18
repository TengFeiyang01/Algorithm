#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    std::vector<std::array<int, 2>> dp(n);    

    std::function<void(int, int)> dfs = [&](int u, int fa) {
    	for (auto v : adj[u]) {
    		if (v == fa) continue;
    		int s = a[u] + a[v];
            dfs(v, u);
            dp[u][0] += std::max(dp[v][0], dp[v][1]);
    	}
        for (auto v : adj[u]) {
            if (v == fa) continue;
            i64 s = std::sqrt(a[u] * a[v]);
            if (s * s == a[v] * a[u]) {
                dp[u][1] = std::max(dp[u][1], (dp[u][0] - std::max(dp[v][0], dp[v][1])) + dp[v][0] + 2);
            }
        }
    };
    dfs(0, -1);
    std::cout << std::max(dp[0][0], dp[0][1]);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
