#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector g(n, std::vector(n, 0));
    for (int i = 0; i < m; ++i) {
    	int x, y, z;
    	std::cin >> x >> y >> z;
    	g[x - 1][y - 1] = z;
    }

    std::vector dp(n, std::vector(n, 0));
    dp[0][0] = g[0][0];
    for (int k = 1; k <= (n - 1) * 2; ++k) {
    	for (int x1 = std::min(k, n - 1); x1 >= std::max(k - n + 1, 0); --x1) {
    		for (int x2 = std::min(k, n - 1); x2 >= x1; --x2) {
    			int y1 = k - x1, y2 = k - x2;
    			int ans = dp[x1][x2];
    			if (x1) ans = std::max(ans, dp[x1 - 1][x2]);
    			if (x2) ans = std::max(ans, dp[x1][x2 - 1]);
    			if (x1 && x2) ans = std::max(ans, dp[x1 - 1][x2 - 1]);
    			ans += g[x1][y1];
    			if (x1 != x2) {
    				ans += g[x2][y2];
    			}
    			dp[x1][x2] = ans;
    		}
    	}
    }
    std::cout << dp.back().back() << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
