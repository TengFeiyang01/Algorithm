#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;


#if 0
void solve() {
    int n, m, root;
    std::cin >> n >> m >> root;
    std::vector<std::vector<int>> adj(n);
    std::vector<std::vector<std::pair<int, int>>> queries(m);
    for (int i = 1, a, b; i < n; ++i) {
    	std::cin >> a >> b;
    	a--, b--;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }
    for (int i = 0, a, b; i < m; ++i) {
    	std::cin >> a >> b;
    	a--, b--;
    	queries[a].push_back({b, i});
    	queries[b].push_back({a, i});
    }
    std::vector<int> ans(n), fa(n);
    std::iota(fa.begin(), fa.end(), 0);
    std::vector<bool> vis(n);

    std::function<int(int)> find = [&](int x) ->int {
    	if (x == fa[x]) return x;
    	return fa[x] = find(fa[x]);
    };

    std::function<void(int)> tarjan = [&](int u) ->void {
    	vis[u] = true;
    	for (auto v : adj[u]) {
    		if (!vis[v]) {
    			tarjan(v);
    			fa[v] = u;
    		}
    	}

    	for (auto [v, id] : queries[u]) {
    		if (vis[v]) {
    			ans[id] = find(v);
    		}
    	}
    };

    tarjan(root - 1);
    for (int i = 0; i < m; ++i) {
    	std::cout << ans[i] + 1 << "\n";
    }
}
#endif


void solve() {
    int n, m, root;
    std::cin >> n >> m >> root;
    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 1, a, b; i < n; ++i) {
        std::cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    std::vector<int> son(n + 1), fa(n + 1), siz(n + 1), dep(n + 1), top(n + 1);

    std::function<void(int, int)> dfs1 = [&](int u, int p) {
        siz[u] = 1;
        dep[u] = dep[p] + 1;
        fa[u] = p;
        for (int v : adj[u]) {
            if (v == p) continue;
            dfs1(v, u);
            siz[u] += siz[v];
            if (siz[son[u]] < siz[v]) {
                son[u] = v;
            }
        }
    };
    dfs1(root, 0);
        
    std::function<void(int, int)> dfs2 = [&](int u, int t) {
        top[u] = t;
        if (!son[u]) return;
        dfs2(son[u], t);
        for (int v : adj[u]) {
            if (v == fa[u] or v == son[u]) continue;
            dfs2(v, v);
        }
    };
    dfs2(root, root);

    std::function<int(int, int)> lca = [&](int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) {
                std::swap(u, v);
            }
            u = fa[top[u]];
        }
        return dep[u] < dep[v] ? u : v;
    };

    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        std::cout << lca(x, y) << "\n";        
    }
}


int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
