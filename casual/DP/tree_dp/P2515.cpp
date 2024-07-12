#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

// Tarjan 缩点 + DP 树上背包
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> cost(n), value(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> cost[i];
    }
    for (int i = 0; i < n; ++i) {
    	std::cin >> value[i];
    }
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n; ++i) {
    	int fa;
    	std::cin >> fa;
    	if (fa) adj[fa - 1].push_back(i);
    }

    std::vector<int> id(n), dfn(n), low(n), vis(n);
    std::stack<int> stk;
    int tot = 0, cnt = 0;

    std::function<void(int)> tarjan = [&](int u) {
    	dfn[u] = low[u] = ++tot;
    	vis[u] = true;
    	stk.push(u);
    	for (auto v : adj[u]) {
    		if (!dfn[v]) {
    			tarjan(v);
    			low[u] = std::min(low[u], low[v]);
    		} else if (vis[v]) {
    			low[u] = std::min(low[u], dfn[v]);
    		}
    	}

    	if (low[u] == dfn[u]) {
    		int y;
    		cnt++;
    		do {
    			y = stk.top();
    			stk.pop();
    			vis[y] = false;
    			id[y] = cnt;
    		} while (y != u);
    	}
    };
    
    for (int i = 0; i < n; ++i) {
        if (!dfn[i]) tarjan(i);
    }

    std::vector<std::vector<int>> nadj(cnt + 1);
    std::vector<int> ncost(cnt + 1), nvalue(cnt + 1), used(cnt + 1);

    for (int u = 0; u < n; ++u) {
        ncost[id[u]] += cost[u];
        nvalue[id[u]] += value[u];
    	for (auto v : adj[u]) {
    		if (id[u] != id[v]) {
    			nadj[id[u]].push_back(id[v]);
                used[id[v]]++;
    		} 
    	}
    }
    for (int i = 1; i <= cnt; ++i) {
    	if (!used[i]) {
    		nadj[0].push_back(i);
    	}
    }

    std::vector dp(cnt + 1, std::vector(m + 1, 0));
    std::function<void(int)> dfs = [&](int u) {
    	for (int i = ncost[u]; i <= m; ++i) {
    		dp[u][i] = nvalue[u];
    	}
    	for (auto v : nadj[u]) {
    		dfs(v);
    		for (int i = m; i >= ncost[u]; --i) {
    			for (int j = 0; j <= i - ncost[u]; ++j) {
                    dp[u][i] = std::max(dp[u][i], dp[v][j] + dp[u][i - j]);
    			}
    		}
    	}
    };

    dfs(0);
    std::cout << dp[0][m] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
