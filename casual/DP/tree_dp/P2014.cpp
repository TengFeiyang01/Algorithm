#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    m++, n++;
    std::vector<std::vector<int>> adj(n);
    std::vector dp(n, std::vector<int>(m + 1, 0));
    std::vector<int> siz(n);
    for (int i = 1; i < n; ++i) {
    	int fa, s;
    	std::cin >> fa >> s;
        dp[i][1] = s;
    	if (!fa) {
    		adj[0].push_back(i);
    	} else {
    		adj[fa].push_back(i);
    	}
    }
    std::function<void(int)> dfs = [&](int u) {
    	siz[u] = 1;
    	for (auto v : adj[u]) {
    		dfs(v);
    		siz[u] += siz[v];
    		for (int j = std::min(siz[u], m); j >= 1; --j) {
                for (int k = 0; k < j and k <= siz[v]; ++k) {
                    dp[u][j] = std::max(dp[u][j], dp[u][j - k] + dp[v][k]);
                }
            }
    	}
    };
    dfs(0);
    std::cout << dp[0][m] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
