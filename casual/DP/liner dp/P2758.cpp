#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s, t;
    std::cin >> s >> t;
    int n = s.size(), m = t.size();
    std::vector dp(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= m; ++i) {
    	dp[0][i] = i;
    }
    for (int i = 1; i <= n; ++i) {
    	dp[i][0] = i;
    }

    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= m; ++j) {
    		dp[i][j] = std::min({dp[i - 1][j - 1] + int(s[i - 1] != t[j - 1]), dp[i][j - 1] + 1, dp[i - 1][j] + 1});
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
