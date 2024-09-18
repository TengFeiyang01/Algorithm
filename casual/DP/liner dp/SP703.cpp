#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int m, n;
    std::cin >> m >> n;
    std::vector g(m, std::vector<int>(m));
    for (int i = 0; i < m; ++i) {
    	for (int j = 0; j < m; ++j) {
    		std::cin >> g[i][j];
    	}
    }
    std::vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> p[i];
        --p[i];
    }
    
    std::vector dp(n + 1, std::vector(m, std::vector(m, inf)));

    dp[0][0][1] = 0;
    p[0] = 2;
    for (int i = 0; i < n; ++i) {
    	for (int x = 0; x < m; ++x) {
    		for (int y = 0; y < m; ++y) {
    			if (x == p[i] or x == y or y == p[i]) continue;
    			dp[i + 1][p[i]][y] = std::min(dp[i + 1][p[i]][y], dp[i][x][y] + g[x][p[i + 1]]);
    			dp[i + 1][x][p[i]] = std::min(dp[i + 1][x][p[i]], dp[i][x][y] + g[y][p[i + 1]]);
    			dp[i + 1][x][y] = std::min(dp[i + 1][x][y], dp[i][x][y] + g[p[i]][p[i + 1]]);
    		}
    	}
    }
    int ans = inf;
    for (int i = 0; i < m; ++i) {
    	ans = std::min(ans, std::ranges::min(dp[n][i]));
    }
    std::cout << ans << "\n";
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
