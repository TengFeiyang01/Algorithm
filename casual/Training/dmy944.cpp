#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, idx, cnt = 0;;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n);

    std::vector<int> dfn(n), low(n), ins(n), bel(n), out(n + 1), siz(n + 1);
    std::stack<int> stk;

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        adj[u].emplace_back(v);
    }

    std::function<void(int)> tarjan = [&](int u) {
        dfn[u] = low[u] = ++idx;
        ins[u] = true;
        stk.push(u);
        for (const int &v : adj[u]) {
            if (!dfn[v]) {
                tarjan(v);
                low[u] = std::min(low[u], low[v]);
            } else {
                if (ins[v]) {
                    low[u] = std::min(low[u], dfn[v]);
                }
            }
        }

        if (dfn[u] == low[u]) {
            ++cnt;
            while (true) {
                int v = stk.top();
                ins[v] = false;
                stk.pop();
                bel[v] = cnt;
                siz[cnt]++;
                if (v == u) break;
            }
        }
    };

    for (int i = 0; i < n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }

    for (int u = 0; u < n; ++u) {
        for (auto v : adj[u]) {
            if (bel[u] != bel[v]) {
                out[bel[u]]++;
            }
        }
    }

    int zero = 0, sum = 0;
    for (int i = 1; i <= cnt; ++i) {
        if (!out[i]) {
            zero++;
            sum += siz[i];
            if (zero > 1) {
                sum = 0;
                break;
            }
        }
    }
    std::cout << sum << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}