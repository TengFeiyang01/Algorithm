#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
const int M = 2333;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector a(n, std::vector<int>(m));
    std::vector dp(n, std::vector<int>(m));
    for (int i = n - 1; i >= 0; --i) {
    	for (int j = 0; j < m; ++j) {
    		std::cin >> a[i][j];
    	}
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		if (a[i][j]) continue;
    		if (i) {
    			dp[i][j] += dp[i - 1][j];
    			dp[i][j] %= M;
    		}
    		if (j) {
    			dp[i][j] += dp[i][j - 1];
    			dp[i][j] %= M;
    		}
    	}
    }
    std::cout << dp[n - 1][m - 1] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
