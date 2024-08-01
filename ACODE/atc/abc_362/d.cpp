#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
    	int u, v, w;
    	std::cin >> u >> v >> w;
    	adj[u - 1].emplace_back(v - 1, w + a[v - 1]);
    	adj[v - 1].emplace_back(u - 1, w + a[u - 1]);
    }

    std::priority_queue<std::pair<i64, int>> pq;
    std::vector<i64> ans(n, 1e18);
    std::vector<int> st(n);

    ans[0] = a[0];
    pq.push({0, 0});
    while (pq.size()) {
    	auto [d, u] = pq.top();
    	pq.pop();
    	if (st[u]) {
    		continue;
    	}
    	st[u] = 1;
    	for (auto [v, w] : adj[u]) {
    		i64 nd = -d + w;
    		if (nd < ans[v]) {
    			ans[v] = nd;
    			pq.push({-nd, v});
    		}
    	}
    }
    for (int i = 1; i < n; ++i) {
    	std::cout << ans[i] + a[0] << " ";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
