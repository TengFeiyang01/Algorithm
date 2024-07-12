#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, t, m;
    std::cin >> n >> t >> m;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
    	int a, b;
    	std::cin >> a >> b;
    	a--, b--;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }

    std::vector<int> a(n, -1);
    i64 ans = 0;

    auto ok = [&](int pos, int u) {
    	for (auto i : adj[pos]) {
    		if (a[i] == u) {
    			return false;
    		}
    	}
    	return true;
    };

    auto dfs = [&](auto dfs, int u, int pos) {
    	if (u > t) return;
    	if (pos == n) {
    		if (u == t) {
    			ans++;
    		}
            return;
    	}
    	for (int i = 0; i < u; ++i) {
    		if (ok(pos, i)) {
    			a[pos] = i;
    			dfs(dfs, u, pos + 1);
    			a[pos] = -1;
    		}
    	}
    	a[pos] = u;
    	dfs(dfs, u + 1, pos + 1);
    	a[pos] = -1;
    };

    dfs(dfs, 0, 0);
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
