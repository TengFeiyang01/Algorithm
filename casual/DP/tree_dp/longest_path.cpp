#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> d1(n), son(n), up(n), d2(n), g[n];
    for (int i = 1; i < n; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	g[x - 1].push_back(y - 1);
    	g[y - 1].push_back(x - 1);
    }

    //求出当前点向下的最长、次长路径。
    std::function<int(int, int)> dfs1 = [&](int u, int fa) ->int {
    	d1[u] = d2[u] = 0;
    	for (int v : g[u]) {
    		if (v == fa) continue;
    		int d = dfs1(v, u);
    		if (1 + d >= d1[u]) {
    			d2[u] = d1[u];
    			d1[u] = d + 1;
    			son[u] = v;
    		} else if (d + 1 > d2[u]) {
    			d2[u] = d + 1;
    		}
    	}
    	return d1[u];
    };

    dfs1(0, -1);

    std::vector<int> ans(n);
    ans[0] = d1[0] + d2[0];

    std::function<void(int, int)> dfs2 = [&](int u, int fa) {
    	for (int v : g[u]) {
    		if (v == fa) continue;
    		if (v == son[u]) {
    			up[v] = std::max(d2[u], up[u]) + 1;
    		} else {
    			up[v] = std::max(d1[u], up[u]) + 1;
    		}
    		dfs2(v, u);
    	}
    };
    dfs2(0, -1);
    for (int i = 0; i < n; ++i) {
    	std::cout << std::max(d2[i], up[i]) + d1[i] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
