#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    
    std::vector<int> dep(n), a(n);
    int lg = std::__lg(n);
    std::vector<std::vector<int>> f(n, std::vector<int>(lg + 1, -1));
    std::function<void(int, int, int)> dfs = [&](int u, int fa, int d) {
    	dep[u] = d;
    	f[u][0] = fa;
    	for (int i = 0; f[u][i] != -1; ++i) {
    		f[u][i + 1] = f[f[u][i]][i];
    	}
    	for (auto v : adj[u]) {
    		if (v != fa) {
    			dfs(v, u, d + 1);
    		}
    	}
    };
    
    dfs(0, -1, 0);

    std::function<int(int, int)> lca = [&](int u, int v) {
    	if (dep[u] > dep[v]) std::swap(u, v);
    	for (int i = lg; i >= 0; --i) {
    		if (dep[u] <= dep[v] - (1 << i)) v = f[v][i];
    	}
    	if (u == v) return u;
    	for (int i = lg; i >= 0; --i) {
    		if (f[u][i] != f[v][i]) {
    			u = f[u][i];
    			v = f[v][i];
    		}
    	}
    	return f[u][0];
    };
    for (int i = 0; i < m; ++i) {
    	int u, v, l;
    	std::cin >> u >> v;
    	--u, --v;
    	l = lca(u, v);
    	++a[u];
    	++a[v];
    	--a[l];
    	if (f[l][0] != -1) --a[f[l][0]];
    }
    
    int ans = 0;
    std::function<void(int, int)> dfs1 = [&](int u, int fa) {
    	for (auto v : adj[u]) {
    		if (v != fa) {
    			dfs1(v, u);
    			a[u] += a[v];
    		}
    	}
    	ans = std::max(ans, a[u]);
    };

    dfs1(0, -1);
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
