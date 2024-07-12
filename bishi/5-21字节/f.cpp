#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    
    int ans = 0;

    auto dfs = [&](auto self, int u, int fa, int d) -> void {
    	if (d == 0) {
    		ans++;
    	}
    	for (auto v : adj[u]) {
    		if (v != fa) {
    			self(self, v, u, d + (s[v] == 'R' ? 1 : -1));
    		}
    	}
    };
    for (int i = 0; i < n; ++i) {
    	dfs(dfs, i, -1, s[i] == 'R' ? 1 : -1);
    }
    std::cout << ans / 2 << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
