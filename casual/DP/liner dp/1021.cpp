#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    int s = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	s += a[i];
    }
    std::vector dp(n + 1, std::vector<int>(2 * s + 1, -inf));
    dp[0][s] = 0;

    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j <= 2 * s; ++j) {
    		dp[i + 1][j] = std::max(dp[i][j], dp[i + 1][j]);
    		if (j - a[i] >= 0) dp[i + 1][j - a[i]] = std::max(dp[i + 1][j - a[i]], dp[i][j] + a[i]);
    		if (j + a[i] <= 2 * s) dp[i + 1][j + a[i]] = std::max(dp[i + 1][j + a[i]], dp[i][j] + a[i]);
    	}
    }
    int ans = 0;
    for (int i = s - m; i <= s + m; ++i) {
    	ans = std::max(ans, dp[n][i]);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
