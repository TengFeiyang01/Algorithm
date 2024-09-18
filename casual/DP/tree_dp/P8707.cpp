#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector dp(n + 1, std::vector<i64>(m + 1));
    dp[1][1] = 1;
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= m; ++j) {
            if (i % 2 == 0 and j % 2 == 0) continue;
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
    	}
    }
    std::cout << dp[n][m];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
