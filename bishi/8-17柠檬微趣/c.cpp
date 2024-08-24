#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

i64 mod = 20220201;

void solve() {
    int n, m, a;
    std::cin >> n >> m >> a;
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    std::vector  dp(n, std::vector(a + 1, -1));
    for (int i = 0; i < m; ++i) {
    	int x, y, z;
    	std::cin >> x >> y >> z;
        --x, --y;
    	adj[y].push_back({x, z});
    }

    int ok = 0;
    auto dfs = [&](auto &&self, int u, int s) -> int {
        if (dp[u][s] != -1) return dp[u][s];
        if (u == 0 and s == 0) return dp[u][s] = 1;
        int res = 0;
        for (auto [v, w] : adj[u]) {
            if (s >= w) {
                res += self(self, v, s - w);
                if (res >= mod) {
                    ok = true;
                    res %= mod;
                }
            }
        }
        return dp[u][s] = res;
    };

    int res = dfs(dfs, n - 1, a);

    if (ok) {
    	std::cout << "All roads lead to Home!\n";
    }
    std::cout << res << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
