#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector dist(n, std::vector(n, inf));
    std::vector dp(n, std::vector(n, std::vector(65, false)));
    for (int i = 0; i < m; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v;
    	dp[u][v][0] = true;
    	dist[u][v] = 1;
    }
    // 倍增+DP+最短路
    // 由于每次可以跑 2^o 那么如果可以从 i-j[2^o-1] 和 j-k[2^o-1] 那么i-j也可以一次到达
    // 先预处理所有能直接到达的点 / 更新边权 再去跑最短路
    for (int o = 1; o <= 64; ++o) {
    	for (int k = 0; k < n; ++k) {
    		for (int i = 0; i < n; ++i) {
    			for (int j = 0; j < n; ++j) {
    				if (dp[i][k][o - 1] and dp[k][j][o - 1]) {
    					dp[i][j][o] = true;
    					dist[i][j] = 1;
    				}
    			}
    		}
    	}
    }

    for (int k = 0; k < n; ++k) {
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < n; ++j) {
    			dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
    		}
    	}
    }
    std::cout << dist[0][n - 1];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
