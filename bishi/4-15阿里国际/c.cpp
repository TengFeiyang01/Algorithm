#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::vector<std::vector<int>> adj(n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
	}

	i64 ans = 0;
	auto dfs = [&](auto &&self, int u, int v) -> int {
		int mn = n, mx = 0, siz = 1;
		for (auto v : adj[u]) {
		 	auto ssiz = self(self, v, u);
			mn = std::min(mn, ssiz);
			mx = std::max(mx, ssiz);
			siz += ssiz;
		}
		if (siz > 1) {
			ans += mx - mn;
		}
		return siz;
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
