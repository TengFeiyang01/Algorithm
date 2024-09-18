#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    std::vector dp(1 << n, std::vector<i64>(n));
    for (int i = 0; i < n; ++i) {
    	dp[1 << i][i] = 1;
    }
    i64 ans = 0;
    for (int s = 1; s < 1 << n; ++s) {
    	for (int i = 0; i < n; ++i) {
    		if (!dp[s][i]) continue;
    		for (auto j : adj[i]) {
    			if ((s & -s) > (1 << j)) continue;
    			if (s >> j & 1) {
    				if ((s & -s) == (1 << j)) {
    					ans += dp[s][i];
    				}
    			} else {
    				dp[s | (1 << j)][j] += dp[s][i];
    			}
    		} 
    	}
    }
    // 因为无向图的存在，会出现（同一条路径出现两次）（一条边和两个端点构成非法环）的情
    std::cout << (ans - m) / 2 << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
