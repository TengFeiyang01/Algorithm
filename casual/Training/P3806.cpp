#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 1; i < n; ++i) {
    	int u, v, w;
    	std::cin >> u >> v >> w;
    	--u, --v;
    	adj[u].emplace_back(v, w);
    	adj[v].emplace_back(u, w);
    }
    std::vector<int> ans(m), siz(n), dis(n), d(n), del(n), ask(m);
    for (int i = 0; i < m; ++i) {
    	std::cin >> ask[i];
    }
    int root, mxs, sum;

    std::function<void(int, int)> getRoot = [&](int u, int fa) -> void {
    	int s = 0;
    	siz[u] = 1;
    	for (auto [v, w] : adj[u]) {
    		if (v == fa || del[v]) continue;
    		getRoot(v, u);
    		siz[u] += siz[v];
    		s = std::max(s, siz[v]);
    	}
    	s = std::max(s, sum - siz[u]);
    	if (s < mxs) {
    		mxs = s;
    		root = u;
    	}
    };

    int cnt = -1;
    std::vector<int> judge(10000005), q(10000005);

    std::function<void(int, int)> getDis = [&](int u, int fa) -> void {
    	dis[++cnt] = d[u];
    	for (auto [v, w] : adj[u]) {
    		if (v == fa || del[v]) continue;
    		d[v] = d[u] + w;
    		getDis(v, u);
    	}
    };

    auto calc = [&](int u) {
    	del[u] = judge[0] = 1;
    	int p = 0;
    	for (auto [v, w] : adj[u]) {
    		if (del[v]) continue;
    		cnt = -1;
    		d[v] = w;
    		getDis(v, u);
    		for (int j = 0; j < cnt; ++j) {
    			for (int k = 0; k < m; ++k) {
    				if (ask[k] >= dis[j]) {
    					ans[k] |= judge[ask[k] - dis[j]];
    				}
    			}
    		}
    		for (int j = 0; j < cnt; ++j) {
    			if (dis[j] < 10000005) {
    				q[++p] = dis[j];
    				judge[dis[j]] = 1;
    			}
    		}
    	}
    	for (int i = 1; i <= p; ++i) {
    		judge[q[i]] = 0;
    	}
    };

    std::function<void(int)> divide = [&](int u) {
    	calc(u);
    	for (auto [v, w] : adj[u]) {
    		if (del[v]) continue;
    		mxs = sum = siz[v];
    		getRoot(v, 0);
    		divide(root);
    	}
    };

    divide(0);
    
    for (int i = 0; i < m; ++i) {
    	std::cout << ans[i] << " \n"[i == m - 1];
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
