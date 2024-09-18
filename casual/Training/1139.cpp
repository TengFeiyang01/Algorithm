#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, s;
    while (std::cin >> n >> m >> s) {
        std::cout << n << " " << m << " " << s << "\n";
    	std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
    	while (m--) {
    		int u, v, w;
    		std::cin >> u >> v >> w;
    		adj[v].emplace_back(u, w);
    	}

        std::function<std::vector<int>()> dijkstra = [&]() ->std::vector<int> {
            std::vector<bool> st(n, false);
            std::vector<int> dist(n, inf);
            dist[s] = 0;
            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
            pq.emplace(0, s);
            while (pq.size()) {
                auto[d, u] = pq.top();
                pq.pop();
                if (st[u]) continue;
                st[u] = true;
                for (auto[v, w] : adj[u]) {
                    if (dist[v] > d + w) {
                        dist[v] = d + w;
                        pq.emplace(d + w, v);
                    }    
                }
            }
            return dist;
        };

        auto dist = dijkstra();

        int t, ans = inf;
        std::cin >> t;
        std::vector<int> a(t);
        for (int i = 0; i < t; ++i) {
            std::cin >> a[i];
            ans = std::min(ans, dist[a[i]]);
        }

        if (ans == inf) {
        	std::cout << "-1\n";
        } else {
        	std::cout << ans << "\n";
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
	solve();

    return 0;
}