#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<std::vector<int>> adj(n);
    for (int x, y, i = 1; i < n; ++i) {
    	std::cin >> x >> y;
    	--x, --y;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    }
    std::vector<int> a(n);
    for (int i = 0; i < q; ++i) {
    	int p, x;
    	std::cin >> p >> x;
    	--p;
    	a[p] += x;
    }
    std::function<void(int, int)> dfs = [&](int u, int fa) ->void {
    	for (int v : adj[u]) {
    		if (v != fa) {
    			a[v] += a[u];
    			dfs(v, u);
    		}
    	}
    };
    dfs(0, -1);
    for (int i = 0; i < n; ++i) {
    	std::cout << a[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}