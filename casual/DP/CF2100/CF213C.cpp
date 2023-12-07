#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector a(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
    		std::cin >> a[i][j];
    	}
    }
    std::vector dp(n, std::vector<int>(n, -inf));
    dp[0][0] = a[0][0];
    for (int k = 1; k < 2 * n - 1; ++k) {
    	for (int x1 = std::min(k, n - 1); x1 > std::max(k - n, -1); --x1) {
    		for (int x2 = std::min(k, n - 1); x2 > x1 - 1; --x2) {
    			int y1 = k - x1, y2 = k - x2;
    			int res = dp[x1][x2];
    			if (x1) res = std::max(res, dp[x1 - 1][x2]);
    			if (x2) res = std::max(res, dp[x1][x2 - 1]);
    			if (x1 && x2) res = std::max(res, dp[x1 - 1][x2 - 1]);
    			res += a[x1][y1];
    			if (x1 != x2) {
    				res += a[x2][y2];
    			}
    			dp[x1][x2] = res;
    		}
    	}
    }
    std::cout << dp[n - 1][n - 1] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
