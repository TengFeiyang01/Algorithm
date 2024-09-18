#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    std::vector<std::pair<int, int>> edges(n - 1);
    std::vector<int> dep(n), f(n, 1);
    for (int i = 0; i < n - 1; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    	edges[i] = {u, v};
    }
    std::vector<int> parent(n);
    parent[0] = -1;

    std::function<void(int)> dfs = [&](int u) {
    	for (auto v : adj[u]) {
    		if (v != parent[u]) {
    			dep[v] = dep[u] + 1;
    			parent[v] = u;
    			dfs(v);
    		}
    	}
    };
    dfs(0);
    std::function<void(int, int, int)> cover = [&](int u, int v, int w) {
    	while (u != v) {
    		if (dep[u] < dep[v]) {
    			f[v] = std::max(f[v], w);
    			v = parent[v];
    		} else {
    			f[u] = std::max(f[u], w);
    			u = parent[u];
    		}
    	}
    };

    auto queryMin = [&](int u, int v) {
    	int w = 10000000;
    	while (u != v) {
    		if (dep[u] < dep[v]) {
    			w = std::min(w, f[v]);
    			v = parent[v];
    		} else {
    			w = std::min(f[u], w);
    			u = parent[u];
    		}
    	}
    	return w;
    };

    std::vector<std::array<int, 3>> paths;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
    	int u, v, w;
    	std::cin >> u >> v >> w;
    	--u, --v;
    	cover(u, v, w);
    	paths.push_back({u, v, w});
    }
    for (auto [u, v, w] : paths) {
    	if (queryMin(u, v) != w) {
    		std::cout << "-1\n";
    		return;
    	}
    }
    for (auto [u, v] : edges) {
    	if (parent[u] == v) std::swap(u, v);
    	std::cout << f[v] << " ";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
