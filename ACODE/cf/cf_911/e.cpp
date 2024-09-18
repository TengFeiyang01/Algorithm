#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v;
    	adj[u].push_back(v);
    }
    std::vector<i64> low(n), dfn(n), c(n), vis(n), sum(n + 1), siz(n + 1);
    int idx = 0, cnt = 0;
    std::stack<int> stk;

    std::function<void(int)> tarjan = [&](int u) {
    	low[u] = dfn[u] = ++idx;
    	vis[u] = 1;
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
    			sum[cnt] += a[y];
    			c[y] = cnt;
    			siz[cnt]++;
    		} while (y != u);
    	}
    };

    for (int i = 0; i < n; ++i) {
    	if (!dfn[i]) {
    		tarjan(i);
    	}
    }

    std::vector<std::vector<int>> dag(cnt + 1);
    std::vector<i64> in(cnt + 1), f(cnt + 1), g(cnt + 1);
    for (int i = 0; i < n; ++i) {
    	for (auto v : adj[i]) {
    		if (c[v] != c[i]) {
    			dag[c[i]].push_back(c[v]);
    			in[c[v]]++;
    		}
    	}
    }

    std::queue<int> q;
    for (int i = 1; i <= cnt; ++i) {
    	if (!in[i]) {
    		q.push(i);
    		g[i] = siz[i];
    		f[i] = sum[i];
    	}
    }
    while (!q.empty()) {
    	auto u = q.front();
    	q.pop();

    	for (auto v : dag[u]) {
    		if (siz[v] + g[u] > g[v]) {
    			g[v] = g[u] + siz[v];
    			f[v] = f[u] + sum[v];
    		} else if (siz[v] + g[u] == g[v] and f[v] > sum[v] + f[u]) {
    			f[v] = sum[v] + f[u];
    		}
    		if (--in[v] == 0) {
    			q.push(v);
    		}
    	}
    }

    i64 len = 0, ans = 0;
    for (int i = 1; i <= cnt; ++i) {
    	if (g[i] > len) {
            len = g[i];
    		ans = f[i];
    	} else if (g[i] == len and f[i] < ans) {
    		ans = f[i];
    	}
    }
    std::cout << len << " " << ans << "\n";
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
