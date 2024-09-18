#include <bits/stdc++.h>
 
const int inf = 2147483647;
using i64 = long long;


void solve() {
	int n, m, s;
	std::cin >> n >> m >> s;
	std::vector<std::vector<std::pair<i64, int>>> adj(n);
	for (int i = 0, x, y, z; i < m; ++i) {
		std::cin >> x >> y >> z;
		adj[x - 1].emplace_back(y - 1, z);
	}

    std::function<std::vector<i64>(int)> dijkstra = [&](int s) ->std::vector<i64> {
        std::vector<bool> st(n, false);
        std::vector<i64> dist(n, inf);
        dist[s] = 0;
        std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<std::pair<i64, int>>> pq;
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
    
    std::ranges::for_each(dijkstra(s - 1), [&](i64 x){std::cout << x << " ";});
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}