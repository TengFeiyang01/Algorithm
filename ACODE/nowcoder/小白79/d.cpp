#include <bits/stdc++.h>
 
using i64 = long long;
const i64 inf = 0x7f7f7f7f;

void solve() {
    i64 n, m, h;
    std::cin >> n >> m >> h;
    std::vector<std::vector<std::array<int, 3>>> adj(n);
    for (int i = 0; i < m; ++i) {
        i64 u, v, w, d;
        std::cin >> u >> v >> w >> d;
        adj[u - 1].push_back({v - 1, w, d});
        adj[v - 1].push_back({u - 1, w, d});
    }
    auto check = [&](i64 k) {
        std::vector<bool> st(n, false);
        std::vector<i64> dist(n, inf);
        dist[0] = 0LL;
        std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<std::pair<i64, int>>> pq;
        pq.emplace(0LL, 0);

        while (pq.size()) {
            auto[d, u] = pq.top();
            pq.pop();
            if (st[u]) continue;
            st[u] = true;
            for (auto[v, w, p] : adj[u]) {
                if (k <= w and dist[v] > d + p) {
                    dist[v] = d + p;
                    pq.emplace(dist[v], v);
                }    
            }
        }
        return dist[n - 1] <= h;
    };

    i64 l = 0, r = 2e9;
    while (l < r) {
        i64 mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    std::cout << r << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}