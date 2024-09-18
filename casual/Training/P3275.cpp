#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
    	int op, u, v;
    	std::cin >> op >> u >> v;
    	--u, --v;
    	switch (op) {
    		case 1:
    			adj[u].emplace_back(v, 0);
    			adj[v].emplace_back(u, 0);
    			break;
    		case 2:
    			adj[u].emplace_back(v, 1);
    			break;
    		case 3:
    			adj[v].emplace_back(u, 0);
    			break;
    		case 4:
    			adj[v].emplace_back(u, 1);
    			break;
    		case 5:
    			adj[u].emplace_back(v, 0);
    			break;
    	}
    }

    std::vector<int> dfn(n), ins(n), low(n), scc(n), cnt(n);
    int idx = 0, tot = 0;
    std::stack<int> st;
    std::function<void(int)> tarjan = [&](int u) {
        low[u] = dfn[u] = idx++;
        ins[u] = true;
        st.push(u);

        for (auto [v, w] : adj[u]) {
            if (!dfn[v]) {
                tarjan(v);
                low[u] = std::min(low[u], low[v]);
            } else if (ins[v]) {
                low[u] = std::min(low[u], dfn[v]);
            }
        }

        if (low[u] == dfn[u]) {
            int y = tot++;
            do {
                y = st.top();
                st.pop();
                ins[y] = false;
                cnt[tot - 1]++;
                scc[y] = tot;
            } while (y != u);

        }
    };

    for (int i = 0; i < n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }

    std::vector<int> d(n);
    std::vector<std::vector<std::pair<int, int>>> nadj(n); 
    for (int i = 0; i < n; ++i) {
        for (auto [j, w] : adj[i]) {
            int x = scc[i], y = scc[j];
            --x, --y;
            if (x == y and w == 1) {
                std::cout << "-1\n";
                return;
            }
            if (x != y) {
                nadj[x].emplace_back(y, w);
                d[y]++;
            }
        }
    }
    std::vector<int> dp(n);
    std::queue<int> q;
    for (int i = 0; i < tot; ++i) {
        if (!d[i]) {
            q.push(i);
            dp[i] = 1;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto [v, w] : nadj[u]) {
            dp[v] = std::max(dp[v], dp[u] + w);
            if (--d[v] == 0) {
                q.push(v);
            }
        }
    }
    i64 ans = 0;
    for (int i = 0; i < tot; ++i) {
        ans += 1LL * dp[i] * cnt[i];
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
