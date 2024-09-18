#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    }
    std::vector<int> st(n, inf);
    st[m] = 0;

    int ans = 0;
    std::function<void(int, int)> dfs = [&](int u, int fa) {
    	if (st[u] <= k) {
    		ans++;
    	}
    	for (auto v : adj[u]) {
    		if (v == fa) continue;
    		if (st[v] > st[u] + 1) {
    			st[v] = st[u] + 1;
    			dfs(v, u);
    		}
    	}
    };
    dfs(m, -1);
    std::cout << ans - 1 << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
