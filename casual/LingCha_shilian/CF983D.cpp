#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 inf = 1e18;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, i64>>> adj(n + 1);

    for (int i = 0; i < m; ++i) {
    	int x, y;
    	i64 w;
    	std::cin >> x >> y >> w;
    	adj[x].emplace_back(y, 2 * w);
    	adj[y].emplace_back(x, 2 * w);
    }
    for (int i = 1; i <= n; ++i) {
    	i64 x;
    	std::cin >> x;
    	adj[0].emplace_back(i, x);
    }

    std::vector<i64> dist(n + 1, inf);
    dist[0] = 0LL;

    std::priority_queue<std::pair<i64, int>> q;
    q.emplace(0, 0);

    while (!q.empty()) {
    	auto [d, u] = q.top();
    	q.pop();

    	if (-d > dist[u]) {
    		continue;
    	}

    	for (auto [v, w] : adj[u]) {
    		if (dist[v] > -d + w) {
    			dist[v] = -d + w;
    			q.emplace(d - w, v);
    		}
    	}
    }
    for (int i = 1; i <= n; ++i) {
    	std::cout << dist[i] << " \n"[i == n];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
