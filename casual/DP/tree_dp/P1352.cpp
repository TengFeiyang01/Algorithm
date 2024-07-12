#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
    	int u, v;
    	std::cin >> u >> v;
        adj[v - 1].push_back(u - 1);
    	adj[u - 1].push_back(v - 1);
    }

    std::function<std::array<int, 2>(int, int)> dfs = [&](int u, int fa) {
    	int go = a[u], not_go = 0;
    	for (auto v : adj[u]) {
            if (v == fa) continue;
    		auto [son_go, son_not_go] = dfs(v, u);
    		go += son_not_go;
    		not_go += std::max(son_go, son_not_go);
    	}
    	return std::array<int, 2>{go, not_go};
    };

    std::cout << std::ranges::max(dfs(0, -1));
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
