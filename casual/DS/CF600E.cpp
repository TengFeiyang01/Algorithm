#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    i64 sum = 0, mx = 0;
    std::vector<i64> a(n + 1), son(n + 1), cnt(n + 1), siz(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        std::cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    std::function<void(int, int)> dfs_init = [&](int u, int fa) {
        siz[u] += 1;
        for (auto v : adj[u]) {
            if (v != fa) {
                dfs_init(v, u);
                siz[u] += siz[v];
                if (siz[v] > siz[son[u]]) {
                    son[u] = v;
                }
            }
        }
    };
    dfs_init(1, 0);
    
    std::function<void(int, int)> add = [&](int u, int fa) {
        cnt[a[u]]++;
        if (cnt[a[u]] > mx) {
            mx = cnt[a[u]];
            sum = a[u];
        } else if (cnt[a[u]] == mx) {
            sum += a[u];
        }
        for (auto v : adj[u]) {
            if (v != fa) {
                add(v, u);
            }
        }
    };
    
    std::function<void(int, int)> del = [&](int u, int fa) {
        cnt[a[u]]--;
        for (auto v : adj[u]) {
            if (v != fa) {
                del(v, u);
            }
        }
    };
    
    std::vector<i64> ans(n + 1);
    
    std::function<void(int, int, bool)> dfs = [&](int u, int fa, bool keep) {
        for (auto v : adj[u]) {
            if (v == fa || v == son[u]) continue;
            dfs(v, u, false);
        }
        if (son[u]) {
            dfs(son[u], u, true);
        }
        for (auto v : adj[u]) {
            if (v == fa || v == son[u]) continue;
            add(v, u);
        }
        cnt[a[u]]++;
        if (cnt[a[u]] > mx) {
            mx = cnt[a[u]];
            sum = a[u];
        } else if (cnt[a[u]] == mx) {
            sum += a[u];
        }
        ans[u] = sum;
        if (!keep) {
            mx = sum = 0;
            del(u, fa);
        }
    };
    
    dfs(1, 0, 0);
    for (int i = 1; i <= n ; ++i) {
        std::cout << ans[i] << " \n"[i == n];
    }
    
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();
    
    return 0;
}