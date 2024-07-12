#include <bits/stdc++.h>

using i64 = long long;
constexpr int inf = 0x3f3f3f3f;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, i64>> g[n];

    for (int i = 1; i < n; ++i) {
        int a, b;
        i64 c;
        std::cin >> a >> b >> c;
        g[a - 1].emplace_back(b - 1, c);
        g[b - 1].emplace_back(a - 1, c);
    }

    std::vector<i64> up(n), f(n);

    std::function<void(int, int)> dfs1 = [&](int u, int fa) {
        bool ok = true;
        for (auto[v, w] : g[u]) {
            if (v == fa) continue;
            dfs1(v, u);
            f[u] += std::min(w, f[v]);
            ok = false;
        }
        if (ok)
            f[u] = inf;
    };

    std::function<void(int, int)> dfs2 = [&](int u, int fa) {
        for (auto[v, w] : g[u]) {
            if (v == fa) continue;
            //此处，根从u->v之后 可能导致u成为叶子结点，此时其能承接的无穷大 仅由w控制
            up[v] = std::min(w, up[u] + f[u] - std::min(w, f[v]));
            if (g[u].size() == 1) up[v] = w;
            dfs2(v, u);
        }
    };
    dfs1(0, -1);
    dfs2(0, -1);
    for (int i = 0; i < n; ++i) {
        std::cout << (f[i] == inf ? 0LL : f[i]) + up[i] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
