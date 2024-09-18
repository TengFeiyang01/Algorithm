#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;


#if 0
void solve() {
    int n, m, root;
    std::cin >> n >> m >> root;
    std::vector<std::vector<int>> adj(n);
    std::vector<std::vector<std::pair<int, int>>> queries(m);
    for (int i = 1, a, b; i < n; ++i) {
        std::cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0, a, b; i < m; ++i) {
        std::cin >> a >> b;
        a--, b--;
        queries[a].push_back({b, i});
        queries[b].push_back({a, i});
    }
    std::vector<int> ans(n), fa(n);
    std::iota(fa.begin(), fa.end(), 0);
    std::vector<bool> vis(n);

    std::function<int(int)> find = [&](int x) ->int {
        if (x == fa[x]) return x;
        return fa[x] = find(fa[x]);
    };

    std::function<void(int)> tarjan = [&](int u) ->void {
        vis[u] = true;
        for (auto v : adj[u]) {
            if (!vis[v]) {
                tarjan(v);
                fa[v] = u;
            }
        }

        for (auto [v, id] : queries[u]) {
            if (vis[v]) {
                ans[id] = find(v);
            }
        }
    };

    tarjan(root - 1);
    for (int i = 0; i < m; ++i) {
        std::cout << ans[i] + 1 << "\n";
    }
}
#endif


void solve() {
    int n, m, root;
    std::cin >> n >> m >> root;

    std::vector<std::vector<int>> adj(n);
    for (auto [a, b, _] : edges) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < queries.size(); ++i) {
        auto[a, b] = queries[i];
        queries[a].push_back({b, i});
        queries[b].push_back({a, i});
    }

    std::vector<int> ans(n), fa(n);
    std::iota(fa.begin(), fa.end(), 0);
    std::vector<bool> vis(n);

    std::function<int(int)> find = [&](int x) ->int {
        if (x == fa[x]) return x;
        return fa[x] = find(fa[x]);
    };

    std::function<void(int)> tarjan = [&](int u) ->void {
        vis[u] = true;
        for (auto v : adj[u]) {
            if (!vis[v]) {
                tarjan(v);
                fa[v] = u;
            }
        }

        for (auto [v, id] : queries[u]) {
            if (vis[v]) {
                ans[id] = find(v);
            }
        }
    };

    std::vector sum(n, std::array<int, 27>{});

    std::function<void(int, int)> dfs = [&](int u, int fa) {
        for (auto [v, w] : adj[u]) {
            if (v == fa) continue;
            sum[v] = sum[u];
            sum[v][w] += 1;
            dfs(v, u);
        }
    };
    


}


int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
