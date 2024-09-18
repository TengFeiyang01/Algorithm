#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> son(n, -1), siz(n);
    std::vector<i64> dis(n), dep(n);
    std::vector<std::vector<std::array<int, 2>>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y, z;
        std::cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }

    std::function<void(int, int)> dfs_init = [&](int u, int fa) ->void {
        siz[u] = 1;
        for (auto [v, w] : adj[u]) {
            if (v == fa) continue;
            dis[v] = dis[u] + w;
            dep[v] = dep[u] + 1;
            dfs_init(v, u);
            siz[u] += siz[v];
            if (son[u] == -1 or siz[v] > siz[son[u]]) {
                son[u] = v;
            }
        }
    };

    dfs_init(0, -1);
    std::unordered_map<i64, i64> val;

    i64 ans = n + 1;

    std::function<void(int, int, bool)> dfs = [&](int u, int fa, bool keep) ->void {
        for (auto [v, w] : adj[u]) {
            if (v == fa or v == son[u]) continue;
            dfs(v, u, false);
        }
        if (son[u] != -1) dfs(son[u], u, true);
        i64 req = dis[fa] + k;

        auto query = [&](int w) ->void {
            i64 d2 = k + 2 * dis[u] - dis[w];
            if (val.count(d2)) {
                ans = std::min(ans, val[d2] + dep[w] - 2 * dep[u]);
            }
        };

        auto add = [&](int w) {
            if (val.count(dis[w])) {
                val[dis[w]] = std::min(val[dis[w]], dep[w]);
            } else {
                val[dis[w]] = dep[w];
            }
        };

        std::function<void(int, int, int)> update = [&](int u, int fa, int op) {
            if (op) {
                query(u);
            } else {
                add(u);
            }
            for (auto [v, w] : adj[u]) {
                if (v != fa) {
                    update(v, u, op);
                }
            }
        };


        for (auto [v, w] : adj[u]) {
            if (v != fa and v != son[u]) {
                update(v, u, 1);
                update(v, u, 0);
            }
        }
        query(u);
        add(u);
        if (!keep) {
            val.clear();
        }
    };
    
    dfs(0, -1, 0);
    if (ans == n + 1) ans = -1;
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
