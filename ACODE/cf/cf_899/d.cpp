#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), siz(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v;
    	adj[u].emplace_back(v);
    	adj[v].emplace_back(u);
    }

    std::vector<i64> cost(n);

    auto dfs = [&](auto self, int u, int fa) ->i64 {
    	siz[u] += 1;
        i64 res = 0;
    	for (auto &v : adj[u]) {
    		if (v != fa) {
    			res += self(self, v, u);
                res += 1LL * siz[v] * (a[u] ^ a[v]);
    			siz[u] += siz[v];
    		}
    	}
        return res;
    };
    cost[0] = dfs(dfs, 0, -1);


    auto reroot = [&](auto &&self, int u, int fa) ->void {
        i64 res = 0;
        for (auto &v : adj[u]) {
            if (v != fa) {
                cost[v] = cost[u] + 1LL * (n - 2 * siz[v]) * (a[u] ^ a[v]);
                self(self, v, u);
            }
        }
        return;
    };
    
    reroot(reroot, 0, -1);
    for (int i = 0; i < n; ++i) {
        std::cout << cost[i] << " \n"[i == n - 1];
    }
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