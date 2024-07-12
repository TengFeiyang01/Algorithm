#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v; 
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    int ans = 0;

    auto dfs = [&](auto &&self, int u, int fa) ->std::pair<int, int> {
    	std::pair<int, int> cur{s[u] == 'B', s[u] == 'R'};

    	for (auto v : adj[u]) {
    		if (v != fa) {
    			auto [b, r] = self(self, v, u);
    			auto &[B, R] = cur;
    			B |= b;
    			R |= r;
    		}
    	}
    	auto &[b, r] = cur;
    	if (b and r) {
    		ans++;
    	}
    	return cur;
    };
    dfs(dfs, 0, -1);
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
