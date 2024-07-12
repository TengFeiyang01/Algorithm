#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> son(n, -1), siz(n), l(n), r(n), id(n);
    std::vector<i64> dis(n), dep(n);
    std::vector<std::vector<std::array<int, 2>>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y, z;
        std::cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    int tot = -1;
    std::function<void(int, int)> dfs_init = [&](int u, int fa) ->void {
        siz[u] = 1;
        l[u] = ++tot;
        id[tot] = u;
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
        r[u] = tot;
    };

    dfs_init(0, -1);
    std::unordered_map<i64, i64> val;

    i64 ans = n + 1;

    std::function<void(int, int, bool)> dfs = [&](int u, int fa, bool keep) ->void {
        for (auto [v, w] : adj[u]) {
            if (v != fa && v != son[u]) {
                dfs(v, u, false);
            }
        }
        if (son[u] != -1) dfs(son[u], u, true);
        auto add = [&](int x) {
            if (val.count(dis[x])) {
                val[dis[x]] = std::min(val[dis[x]], dep[x]);
            } else {
                val[dis[x]] = dep[x];
            }
        };

        auto query = [&](int x) {
            i64 d2 = k + 2 * dis[u] - dis[x];
            if (val.count(d2)) {
                ans = std::min(ans, val[d2] + dep[x] - 2 * dep[u]);
            }
        };
        for (auto [v, w] : adj[u]) {
            if (v != fa && v != son[u]) {
                for (int x = l[v]; x <= r[v]; ++x) {
                    query(id[x]);
                }
                for (int x = l[v]; x <= r[v]; ++x) {
                    add(id[x]);
                }
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
