#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, p;
    std::cin >> n >> m >> p;
    std::vector a(n + 1, std::vector(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= m; ++j) {
    		std::cin >> a[i][j];
    	}
    }

    std::vector<int> cost(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> cost[i];
    }
    
    std::vector<int> dp(m + 1, -1e9);
    dp[0] = 0;

    //TODO 单调队列优化
    for (int i = 1; i <= m; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		int ans = -cost[j] + dp[i - 1];
    		for (int k = 0; k < p and i + k <= m; ++k) {
    			int t = j + k > n ? ((j + k) % n) : j + k;
    			ans += a[t][i + k];
    			dp[i + k] = std::max(dp[i + k], ans);
    		}
    	}
    }
    std::cout << dp[m] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
