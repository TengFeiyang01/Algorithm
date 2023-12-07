#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> d(n), ind(n);
    std::vector<double> dp(n);
    std::vector<std::vector<std::pair<int, i64>>> adj(n);
    for (int i = 0; i < m; ++i) {
    	int u, v, w;
    	std::cin >> u >> v >> w;
    	--u, --v;
    	adj[v].emplace_back(u, w);
    	d[u]++;
        ind[u]++;
    }
    dp[n - 1] = 0;
    std::queue<int> q;
    for (int i = 0; i < n; ++i) {
    	if (d[i] == 0) q.push(i);
    }
    while (!q.empty()) {
    	int u = q.front();
    	q.pop();
    	for (auto [v, w] : adj[u]) {
    		if (--d[v] == 0) {
    			q.push(v);
    		}
    		dp[v] += (dp[u] + w) / ind[v];
    	}
    }

    std::cout << std::fixed << std::setprecision(2) << dp[0] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
	