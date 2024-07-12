#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --v, --u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<int> son(n, -1), size(n), l(n), r(n), id(n);
    int tot = -1;
    std::function<void(int, int)> dfs = [&](int u, int fa) -> void {
        size[u] = 1;
        l[u] = ++tot;
        id[tot] = u;
        for (auto v : adj[u]) {
            if (v == fa) continue;
            dfs(v, u);
            size[u] += size[v];
            if (son[u] == -1 || size[son[u]] < size[v]) {
                son[u] = v;
            }
        }
        r[u] = tot;
    };

    dfs(0, -1);
    std::map<int, int> cnt;
    i64 maxCnt = 0, sumCnt = 0;
    std::vector<i64> ans(n);

    std::function<void(int, int, bool)> dfs_solve = [&](int u, int fa, bool keep) -> void {
        for (auto v : adj[u]) {
            if (v != fa && v != son[u]) {
                dfs_solve(v, u, false);
            }
        }
        if (son[u] != -1) {
            dfs_solve(son[u], u, true);
        }

        auto add = [&](int x) {
            x = a[x];
            cnt[x]++;
            if (cnt[x] > maxCnt) {
                maxCnt = cnt[x];
                sumCnt = 0;
            } 
            if (cnt[x] == maxCnt) {
                sumCnt += x;
            }
        };

        auto del = [&](int x) {
            x = a[x];
            cnt[x]--;
        };
        for (auto v : adj[u]) {
            if (v != fa && v != son[u]) {
                for (int x = l[v]; x <= r[v]; ++x) {
                    add(id[x]);
                }
            }
        }
        add(u);
        ans[u] = sumCnt;
        if (!keep) {
            maxCnt = 0;
            sumCnt = 0;
            for (int x = l[u]; x <= r[u]; ++x) {
                del(id[x]);
            }
        }
    };
    dfs_solve(0, -1, false);
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
