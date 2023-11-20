#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, idx = 0, cnt = 0;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v;
    	adj[u].push_back(v);
    }
    int s, p;

    std::vector<int> dfn(n), low(n), ins(n), a(n), bar(n), bel(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::cin >> s >> p;
    std::stack<int> stk;

    for (int i = 1; i <= p; ++i) {
    	int x;
    	std::cin >> x;
    	bar[--x] = 1;
    }

    std::vector<i64> dp(n);
    i64 ans = 0;

    std::function<void(int)> tarjan = [&](int u) {
    	dfn[u] = low[u] = ++idx;
    	stk.push(u);
    	ins[u] = true;
    	for (int &v : adj[u]) {
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
    		int y;
    		++cnt;
    		dp[cnt] = -1e15;
    		bool has_bar = false;
    		i64 sval = 0;
    		do {
    			y = stk.top();
    			stk.pop();
    			bel[y] = cnt;
    			sval += a[y];
    			if (bar[y]) {
    				has_bar = true;
    			}
    			ins[y] = false;
    			for (int v : adj[y]) {
    				int ne = bel[v];
    				if (ne != cnt && ne != 0) {
    					dp[cnt] = std::max(dp[cnt], dp[ne]);
    				}
    			}
    		} while (y != u);
	    	if (has_bar) dp[cnt] = std::max(0LL, dp[cnt]);
	    	dp[cnt] += sval;
	    	ans = std::max(ans, dp[cnt]);
    	}
    };

    tarjan(s - 1);
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}