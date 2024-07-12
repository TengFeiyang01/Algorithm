#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 1; i < n; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    i64 ans = 0;

    auto dfs = [&](auto &&self, int u, int fa) ->void {
    	i64 x = n / 2, s = 1;
    	for (auto v : adj[u]) {
    		if (v % 2 == 0) {
    			x--;
    		}
    		s++;
    	}
    	if (u % 2 == 0) {
    		ans += n - s;
    	} else {
	    	ans += x;
    	}
    	for (auto v : adj[u]) {
    		if (v != fa) {
    			self(self, v, u);
    		}
    	}
    };
    dfs(dfs, 1, 0);
    std::cout << ans / 2 << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
