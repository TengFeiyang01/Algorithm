#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> sz(n);
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    
    int ans = 0;
    std::function<void(int, int)> dfs = [&](int u, int fa) {
        sz[u] = 1;
        for (auto v : adj[u]) {
            if (v != fa) {
                dfs(v, u);
                sz[u] += sz[v];
                if (u == 0) {
                    ans = std::max(ans, sz[v]);
                }
            }
        }
    };
    dfs(0, -1);
    std::cout << sz[0] - ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
