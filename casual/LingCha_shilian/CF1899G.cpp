#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<std::vector<int>> adj(n);
    std::vector<int> p(n), pos(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
        p[i]--;
        pos[p[i]] = i;
    }

    std::vector<std::vector<std::array<int, 3>>> queries(n);
    for (int i = 0; i < q; ++i) {
        int l, r, x;
        std::cin >> l >> r >> x;
        --l, --r, --x;
        queries[x].push_back({l, r, i});
    }

    std::vector<int> ans(q);

    std::function<std::set<int>(int, int)> dfs = [&](int u, int fa) {
        std::set<int> su{pos[u]};
        for (auto v : adj[u]) {
            if (v != fa) {
                auto sv = dfs(v, u);
                if (sv.size() > su.size()) {
                    std::swap(su, sv);
                }
                for (auto x : sv) {
                    su.insert(x);
                }
                sv.clear();
            }
        }
        for (auto [l, r, id] : queries[u]) {
            auto it = su.lower_bound(l);
            if (it != su.end() and *it <= r) {
                ans[id] = 1;
            }
        }
        return su;
    };
    
    dfs(0, -1);
    for (int i = 0; i < q; ++i) {
        std::cout << (ans[i] ? "YES" : "NO") << "\n";
    }
    std::cout << "\n";
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