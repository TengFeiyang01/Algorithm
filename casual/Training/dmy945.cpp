#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, idx, cnt = 0, x, t = 0;
    std::cin >> n >> m >> x;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u - 1].emplace_back(v - 1);
    }
    std::vector<int> dfn(n), low(n), ins(n), dp(n), bel(n), way(n), vis(n);
    std::stack<int> stk;
    int ans = 0, res = 0;

    std::function<void(int)> tarjan = [&](int u) {
        dfn[u] = low[u] = ++idx;
        stk.push(u);
        ins[u] = true;
        for (auto v : adj[u]) {
            if (!dfn[v]) {
                tarjan(v);
                low[u] = std::min(low[u], low[v]);
            } else {
                if (ins[v]) {
                    low[u] = std::min(low[u], dfn[v]);
                }
            }
        }

        if (low[u] == dfn[u]) {
            ++cnt;
            int y, sz = 0;
            ++t;
            vis[cnt] = t;
            dp[cnt] = 0;
            way[cnt] = 1;
            do {
                y = stk.top();
                stk.pop();
                ins[y] = false;
                bel[y] = cnt;
                sz++;
                for (int v : adj[y]) {
                    if (vis[bel[v]] != t) {
                        vis[bel[v]] = t;
                        if (dp[bel[v]] > dp[cnt]) {
                            dp[cnt] = dp[bel[v]];
                            way[cnt] = 0;
                        } 
                        if (dp[bel[v]] == dp[cnt]) {
                            way[cnt] = (way[bel[v]] + way[cnt]) % x;
                        }
                    }
                }
            } while (y != u);
            dp[cnt] += sz;
            if (dp[cnt] > ans) {
                ans = dp[cnt];
                res = 0;
            }
            if (dp[cnt] == ans) {
                res = (res + way[cnt]) % x;
            }
        }
    };

    for (int i = 0; i < n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }

    std::cout << ans << "\n" << res << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}