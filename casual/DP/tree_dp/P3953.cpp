#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, k, p;
    std::cin >> n >> m >> k >> p;
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    std::vector<std::vector<std::pair<int, int>>> radj(n);
    for (int i = 0; i < m; ++i) {
    	int u, v, w;
    	std::cin >> u >> v >> w;
    	--u, --v;
    	adj[u].push_back({v, w});
    	radj[v].push_back({u, w});
    }
    std::vector<int> dist(n, inf), vis(n);
    std::priority_queue<std::pair<int, int>> pq;
    pq.emplace(0, 0);
    dist[0] = 0;
    while (!pq.empty()) {
    	auto [d, u] = pq.top();
    	pq.pop();
    	if (vis[u]) continue;
        vis[u] = true;
    	for (auto [v, w] : adj[u]) {
    		if (dist[v] > -d + w) {
    			dist[v] = -d + w;
    			pq.emplace(-dist[v], v);
    		}
    	}
    }

    int fail = 0;

    std::vector memo(n, std::vector(k + 1, -1));
    std::vector st(n, std::vector(k + 1, 0));
    std::function<int(int, int)> dp = [&](int u, int k) {
    	if (k < 0) return 0;
    	if (st[u][k]) {
    		fail = 1;
    		return 0;
    	}
    	if (memo[u][k] != -1) return memo[u][k];
    	st[u][k] = 1;
    	int ans = 0;
    	for (auto [v, w] : radj[u]) {
    		// dist[v] + x + w == dist[u] + k
    		ans += dp(v, dist[u] - dist[v] + k - w);
    		ans %= p;
    		if (fail == 1) return 0;
    	}
    	st[u][k] = 0;
    	return memo[u][k] = ans;
    };

    // 从0出发走 如果存在0环 即可以回到0 那么答案是无穷大
    dp(0, 0);
    memo[0][0] = 1;
    
    int ans = 0;
    for (int i = 0; i <= k; ++i) {
    	ans += dp(n - 1, i);
    	ans %= p;
    }
    if (fail) {
    	std::cout << "-1\n";
    } else {
    	std::cout << ans << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
