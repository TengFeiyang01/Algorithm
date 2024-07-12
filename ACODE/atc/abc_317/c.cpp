#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    std::cin >> N >> M;
    
    std::vector g(N, std::vector<int>(N));
    for (int i = 0; i < M; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        g[u][v] = g[v][u] = w;
    }
    
    int ans = 0;
    std::vector<bool> vis(N);
    auto dfs = [&](auto self, int x, int sum) -> void {
        vis[x] = true;
        ans = std::max(ans, sum);
        for (int y = 0; y < N; y++) {
            if (g[x][y] > 0 && !vis[y]) {
                self(self, y, sum + g[x][y]);
            }
        }
        vis[x] = false;
    };
    for (int s = 0; s < N; s++) {
        dfs(dfs, s, 0);
    }
    std::cout << ans << "\n";
    
    return 0;
}