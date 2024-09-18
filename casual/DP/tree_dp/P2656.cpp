#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

constexpr int N = 2e5 + 13;
int low[N], dfn[N], c[N], vis[N], tot = 0, cnt = 0;

void solve() {
    int n, m, s;
    std::cin >> n >> m;
    std::vector<std::vector<std::array<int, 3>>> adj(n);
    for (int i = 0; i < m; ++i) {
    	int u, v, w;
    	double p;
    	std::cin >> u >> v >> w >> p;
        --u, --v;
    	adj[u].push_back({v, int(p * 10), w});
    }
    std::cin >> s; s--;

    std::stack<int> st;
    std::function<void(int)> tarjan = [&](int u) {
        low[u] = dfn[u] = ++tot;
        st.push(u);
        vis[u] = true;

        for (auto [v, p, w] : adj[u]) {
            if (!dfn[v]) {
                tarjan(v);
                low[u] = std::min(low[u], low[v]);
            } else if (vis[v]) {
                low[u] = std::min(low[u], dfn[v]);
            }
        }

        if (low[u] == dfn[u]) {
            ++cnt;
            int y;
            do {
                y = st.top();
                st.pop();
                c[y] = cnt;
                vis[y] = false;
            } while (y != u);
        }
    };

    for (int i = 0; i < n; ++i) {
        if (!dfn[i]) tarjan(i);
    }

    std::vector<std::vector<std::pair<int, int>>> nadj(cnt);
    std::vector<int> a(cnt), ind(cnt);
    for (int i = 0; i < n; ++i) --c[i];

    // 缩点 建新边
    for (int u = 0; u < n; ++u) {
        for (auto [v, p, w] : adj[u]) {
            if (c[u] != c[v]) {
                nadj[c[u]].push_back({c[v], w});
                ind[c[v]]++;
            } else {
                int sum = 0, now = w;
                while (now) {
                    sum += now;
                    now = now * p;
                    now /= 10;
                }
                a[c[u]] += sum;
            }
        }
    }

    std::queue<int> q;
    std::vector<int> dp(cnt, -inf);
    for (int i = 0; i < cnt; ++i) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }

    // 跑拓扑+DP
    dp[c[s]] = a[c[s]];
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto [v, w] : nadj[u]) {
            dp[v] = std::max(dp[v], dp[u] + a[v] + w);
            if (--ind[v] == 0) {
                q.push(v);
            }
        }
    }
    std::cout << std::ranges::max(dp);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
