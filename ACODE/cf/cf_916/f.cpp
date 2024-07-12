#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> siz(n);
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
    	int f;
    	std::cin >> f;
    	adj[f - 1].push_back(i);
    }

    auto dfs1 = [&](auto self, int u) ->void {
    	siz[u] = 1;
    	for (auto v : adj[u]) {
    		self(self, v);
    		siz[u] += siz[v];
    	}
    };
    dfs1(dfs1, 0);

    auto dfs = [&](auto self, int u) -> int {
        int max = 0;
        for (auto v : adj[u]) {
            max = std::max(max, siz[v]);
        }
        if (max * 2 > siz[u] - 1) {
            for (auto v : adj[u]) {
                if (siz[v] == max) {
                    int x = self(self, v);
                    return x + std::min((siz[u] - 1 - 2 * x) / 2, siz[u] - 1 - max);  // 匹配玩之后剩下的
                }
            }
        } else {
            return (siz[u] - 1) / 2;
        }
    };

    int ans = dfs(dfs, 0);
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
