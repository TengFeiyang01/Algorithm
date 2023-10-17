#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	--x, --y;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    }
    i64 ans = 0;
    std::vector<i64> sz(n);
    std::function<void(int, int)> dfs = [&](int u, int fa) {
    	sz[u] += 1;
    	for (auto v : adj[u]) {
    		if (v == fa) continue;
    		dfs(v, u);
    		sz[u] += sz[v];
    		ans += (sz[v] * (n - sz[u]));
    	}
    };
    dfs(0, -1);
    std::cout << (n - 2LL) * (n - 1) * n / 6 - ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
