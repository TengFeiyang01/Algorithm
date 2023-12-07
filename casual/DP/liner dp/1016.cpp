#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector dp(n + 1, std::vector<i64>(m + 1, -1e15));
    std::vector<i64> a(n);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i - 1];
    	dp[i][1] = std::max(dp[i - 1][1], a[i - 1]);
    }
    for (int i = k + 1; i <= n; ++i) {
    	for (int j = 2; j <= m; ++j) {
    		dp[i][j] = std::max(dp[i - 1][j], dp[i - k][j - 1] + a[i - 1]);
    	}
    }
    std::cout << dp[n][m] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
