#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
    i64 res = 0;
    for (int i = 0; i < n - 1; ++i) {
    	int x, y, w;
    	std::cin >> x >> y >> w;
    	res += 2LL * w;
    	adj[x].push_back({y, w});
    	adj[y].push_back({x, w});
    }

    std::vector<i64> d(n + 1);

    int c = 0;

    std::function<void(int, int)> dfs = [&](int u, int fa) -> void {
    	for (auto t : adj[u]) {
    		int v = t.first, w = t.second;
    		if (v == fa) continue;
    		d[v] = d[u] + w;
    		if (d[v] > d[c]) c = v;
    		dfs(v, u);
    	}
    };

    dfs(1, 0);
    
    std::cout << res - d[c] << "\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
