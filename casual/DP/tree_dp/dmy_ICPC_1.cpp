#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

/*
	f[i]:表示以i这个节点为根的子树，i这个节点不能选的最优解
	g[i]:表示以i这个节点为根的子树，i这个节点要选的最优解
	h[i]:表示以i这个节点为根的子树，i这个节点要选，但是i的儿子不能选的最优解
*/

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n), t(n);
    std::vector<int> adj[n];
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < n; ++i) std::cin >> t[i];
    for (int i = 1, u, v; i < n; ++i) {
    	std::cin >> u >> v;
    	--v, --u;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    std::vector<i64> f(n), h(n);

    std::function<void(int, int)> dfs = [&](int u, int fa) {
    	i64 s = 0, mx = 0;
    	for (auto &v : adj[u]) {
    		if (v == fa) continue;
    		dfs(v, u);
    		s += f[v];
    		mx = std::max(mx, a[v]);
    	}

    	f[u] = s + mx;

    	std::pair<i64, int> mx1{-1e15, -1}, mx2{-1e15, -1};
    	for (auto &v : adj[u]) {
    		if (v == fa or t[v] != 3) continue;
    		std::pair<i64, int> mx3(a[v], v);
    		if (mx3 > mx2) mx2 = mx3;
    		if (mx2 > mx1) std::swap(mx2, mx1);
    	}

    	for (auto &v : adj[u]) {
    		if (v == fa) continue;
    		i64 tmp = s + h[v] - f[v];
    		if (v == mx1.second) tmp += mx2.first;
    		else tmp += mx1.first;
    		f[u] = std::max(f[u], tmp);
    	}
    	h[u] = s + a[u];
    };

    dfs(0, -1);
    std::cout << f[0] + a[0] << "\n";
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
