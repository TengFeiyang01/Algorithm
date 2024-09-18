#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    int ans = 0;
    std::vector<std::array<int, 2>> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
    	if (s[i - 1] == '0') {
    		dp[i][0] = dp[i - 1][0] + 1;
    	} else if (s[i - 1] == '1') {
    		dp[i][1] = dp[i - 1][1] + 1;
    	} else {
    		dp[i][0] = dp[i - 1][0] + 1;
    		dp[i][1] = dp[i - 1][1] + 1;
    	}
    	ans = std::max({ans, dp[i][0], dp[i][1]});
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
