#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	adj[x - 1].push_back(y - 1);
    	adj[y - 1].push_back(x - 1);
    }

    std::vector<int> size(n);
    
    i64 ans = 1;

    std::function<void(int, int)> dfs = [&](int u, int fa) -> void {
    	size[u] = 1;
    	int cnt = 0;
    	for (auto v : adj[u]) {
    		if (v == fa) continue;
    		dfs(v, u);
    		size[u] += size[v];
    		if (size[v] % 2) cnt++;
    	}
    	// 父节点参与匹配
    	if (cnt % 2) cnt++;
    	for (int i = cnt - 1; i >= 1; i -= 2) {
    		ans = ans * i % mod;
    	}
    };
    dfs(0, -1);
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
