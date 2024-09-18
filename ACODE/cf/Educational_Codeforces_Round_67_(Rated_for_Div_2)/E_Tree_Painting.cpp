#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n);

    for (int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<i64> siz(n);

    std::function<i64(int, int)> dfs = [&](int u, int fa) -> i64 {
        siz[u] = 1;
        i64 sum = 0;
        for (auto v : adj[u]) {
            if (v != fa) {
                sum += dfs(v, u);
                siz[u] += siz[v];
            }
        }        
        return sum + siz[u];
    };

    i64 ans = 0;

    std::function<void(int, int, i64)> reroot = [&](int u, int fa, i64 res) {
        ans = std::max(ans, res);
        for (auto v : adj[u]) {
            if (v != fa) {
                reroot(v, u, res + n - 2LL * siz[v]);
            }
        }
    };

    reroot(0, -1, dfs(0, -1));

    std::cout << ans << "\n";
}   

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
