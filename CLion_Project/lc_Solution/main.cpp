#include <bits/stdc++.h>

constexpr int inf = 0x3f3f3f3f;
using i64 = long long;


int main() {
    std::istream::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> g(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
//        g[u].push_back({v, w});
        g[u].emplace_back(v, w);
    }

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;

    std::vector<int> dist(n + 1, inf);
    std::vector<bool> vis(n + 1);
    dist[1] = 0;
    q.emplace(0, 1);
//    q.push({0, 1});

    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;

        for (auto &[v, w] : g[u]) {
            if (!vis[v] && dist[v] > d + w) {
                dist[v] = d + w;
                q.emplace(dist[v], v);
            }
        }
    }

    std::cout << (dist[n] == inf ? -1 : dist[n]) << "\n";
}
