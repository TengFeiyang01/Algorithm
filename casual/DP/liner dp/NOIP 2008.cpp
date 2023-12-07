#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector dp(m + 1, std::vector<int>(n));
    dp[0][0] = 1;
    for (int i = 1; i <= m; ++i) {
    	for (int j = 0; j < n; ++j) {
    		dp[i][j] = dp[i - 1][(j - 1 + n) % n] + dp[i - 1][(j + 1) % n];
    	}
    }
    std::cout << dp[m][0] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
