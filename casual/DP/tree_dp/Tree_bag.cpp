#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<PII> g[n];
    for (int i = 1; i < n; ++i) {
    	int u, v, w;
    	std::cin >> u >> v >> w;
    	--u, --v;
    	g[u].emplace_back(v, w);
    	g[v].emplace_back(u, w);
    }
    std::vector f(n, std::vector<int>(n));
    std::vector<int> siz(n);

    std::function<void(int, int)> dfs = [&](int u, int p) {
    	for (auto [v, w] : g[u]) {
    		if (v == p) continue;
            dfs(v, u);
    		for (int k = m; k >= 1; --k)
    			for (int j = 1; j <= k; ++j)
                    //之所以是j - 1是因为 u->v 还有一条边
    				f[u][k] = std::max(f[u][k], f[u][k - j] + f[v][j - 1] + w);
    	}
    };
    dfs(0, -1);
    std::cout << f[0][m] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
