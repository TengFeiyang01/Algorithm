#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), d(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    int ans = 0;
    d[0] = a[0];
    std::vector<std::set<int>> st(n);
    std::function<void(int, int)> dfs = [&](int u, int fa) {
    	st[u].insert(d[u]);
    	bool ok = false;

    	for (auto v : adj[u]) {
    		if (v != fa) {
    			d[v] = d[u] ^ a[v];
    			dfs(v, u);
    			
    			if (st[u].size() < st[v].size()) {
    				std::swap(st[u], st[v]);
    			}
    			for (int x : st[v]) {
    				if (st[u].count(x ^ a[u])) {
    					ok = true;
    				}
    			}
    			for (auto x : st[v]) {
    				st[u].insert(x);
    			}
    		}
    	}
    	if (ok) {
    		ans++;
    		st[u].clear();
    	}
    };
    dfs(0, -1);
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
