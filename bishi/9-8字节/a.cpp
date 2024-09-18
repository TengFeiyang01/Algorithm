#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	adj[x - 1].push_back(y - 1);
    	adj[y - 1].push_back(x - 1);
    }
    i64 ans = 0;

    std::function<i64(int, int)> dfs = [&](int u, int fa) -> i64 {
    	i64 tot = 0, cur = a[u];
    	for (auto v : adj[u]) {
    		if (v == fa) continue;
    		tot += dfs(v, u);
    	}
    	if (cur < tot) {
    		ans += tot - cur;
    		cur = tot;
    	}
    	return cur;
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
