#include <bits/stdc++.h>

using i64 = long long;

struct HLD {
    int n;
    std::vector<int> a, pos;
    std::vector<int> sz, fa;
    std::vector<std::vector<int>> g;
    std::vector<bool> exist;
    std::vector<int> ans;
    int res;
    
    HLD() {}
    HLD(int n) {
        init(n);
    }
    void init(int n) {
        this->n = n;
        a.resize(n);
        pos.resize(n);
        sz.resize(n);
        fa.resize(n);
        g.assign(n, {});
        exist.assign(n, false);
        ans.resize(n);
        res = 0;
    }
    void addEdge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void work(int root = 0) {
        fa[root] = -1;
        dfs1(root);
        for (int i = 0; i < n; i++) {
            pos[a[i]] = i;
        }

        solve(root, true);
    }
    void dfs1(int u) {
        if (fa[u] != -1) {
            g[u].erase(std::find(g[u].begin(), g[u].end(), fa[u]));
        }
        
        sz[u] = 1;
        for (auto &v : g[u]) {
            fa[v] = u;
            dfs1(v);
            sz[u] += sz[v];
            if (sz[v] > sz[g[u][0]]) {
                std::swap(v, g[u][0]);
            }
        }
    }
    void add_subtree(int u, int ignore = -1) {
        exist[pos[u]] = true;
        res++;
        if (pos[u] - 1 >= 0 && exist[pos[u] - 1]) {
            res--;
        }
        if (pos[u] + 1 < n && exist[pos[u] + 1]) {
            res--;
        }
        for (auto v : g[u]) {
            if (v == ignore) continue;
            add_subtree(v);
        }
    }
    void delete_subtree(int u) {
        exist[pos[u]] = false;
        res--;
        if (pos[u] - 1 >= 0 && exist[pos[u] - 1]) {
            res++;
        }
        if (pos[u] + 1 < n && exist[pos[u] + 1]) {
            res++;
        }
        for (auto v : g[u]) {
            delete_subtree(v);
        }
    }
    void solve(int u, bool keep) {
        for (auto v : g[u]) {
            if (v == g[u].front()) continue;
            solve(v, false);
        }
        if (g[u].size()) {
            solve(g[u].front(), true);
        }

        add_subtree(u, g[u].size() ? g[u].front() : -1);
        ans[u] = res;

        if (!keep) {
            delete_subtree(u);
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    HLD hld(n);
    for (auto &i : hld.a) {
        std::cin >> i;
        i--;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        hld.addEdge(u, v);
    }

    hld.work();

    std::cout << std::fixed << std::setprecision(10);
    std::cout << std::accumulate(hld.ans.begin(), hld.ans.end(), 0.) / n << '\n';

    return 0;
}
