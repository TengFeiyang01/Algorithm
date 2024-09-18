#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    int lg = std::__lg(n);
    std::vector<int> a(n), w(n), dep(n);
    std::vector<std::vector<int>> adj(n), f(n, std::vector<int>(lg + 1, -1));

    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
        --a[i];
    }

    for (int i = 1; i < n; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v;
    	adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::function<void(int, int, int)> dfs = [&](int u, int fa, int d) {
    	dep[u] = d;
    	f[u][0] = fa;
    	int s = 0;
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

    for (int i = 1; i < n; ++i) {
    	int x = a[i - 1], y = a[i];
        int l = lca(x, y);
    	++w[x];
    	++w[y];
    	--w[l];
    	if (f[l][0] != -1) --w[f[l][0]];
    }

    std::function<int(int, int)> dfs1 = [&](int u, int fa) {
    	for (auto v : adj[u]) {
    		if (v != fa) {
    			w[u] += dfs1(v, u);
    		}
    	}
        return w[u];
    };
    
    dfs1(0, -1);
    
    for (int i = 0; i < n; ++i) {
        if (i == a[0]) {
            std::cout << w[i] << "\n";
        } else {
            std::cout << w[i] - 1 << "\n";
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
