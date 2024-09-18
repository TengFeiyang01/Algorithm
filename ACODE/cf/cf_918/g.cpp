#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<i64, i64>>> adj(n);
    for (int i = 0; i < m; ++i) {
    	i64 u, v, w;
    	std::cin >> u >> v >> w;
    	--u, --v;
    	adj[u].emplace_back(v, w);
    	adj[v].emplace_back(u, w);
    }

    std::vector<i64> s(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> s[i];
    }
    std::vector dist(n, std::vector<i64>(1001, 1e18));
    std::vector vis(n, std::vector<bool>(1001, false));
    dist[0][s[0]] = 0;
    
    std::priority_queue<std::array<i64, 3>, std::vector<std::array<i64, 3>>, std::greater<std::array<i64, 3>>> pq;
    
    pq.push({0LL, 0LL, s[0]});

    while (!pq.empty()) {
        auto p = pq.top();
        i64 d = p[0], u = p[1], x = p[2];
        pq.pop();

        if (vis[u][x]) continue;
        vis[u][x] = true;
        for (auto [v, w] : adj[u]) {
            i64 y = std::min(x, s[v]);
            if (dist[u][x] + x * w < dist[v][y]) {
                dist[v][y] = dist[u][x] + x * w;
                pq.push({dist[v][y], v, y});
            }
        }
    }

    i64 ans = 1e15;
    for (int i = 1; i <= 1000; ++i) {
        ans = std::min(ans, dist[n - 1][i]);
    }
    std::cout << ans << "\n";
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
