#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    /*
    std::vector dp(n, std::vector<int>(3));
   
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < 3; ++j) {
    		std::cin >> dp[i][j];
    	}
    	if (i) {
    		dp[i][0] += std::max(dp[i - 1][1], dp[i - 1][2]);
    		dp[i][1] += std::max(dp[i - 1][0], dp[i - 1][2]);
    		dp[i][2] += std::max(dp[i - 1][0], dp[i - 1][1]);
    	}
    }
    std::cout << std::max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    */
    std::vector<int> dp(3);
    std::cin >> dp[0] >> dp[1] >> dp[2];
    for (int i = 1; i < n; ++i) {
        auto f = dp;
        std::cin >> f[0] >> f[1] >> f[2];
        f[0] += std::max(dp[1], dp[2]);
        f[1] += std::max(dp[0], dp[2]);
        f[2] += std::max(dp[0], dp[1]);
        dp = f;
    }
    std::cout << std::max({dp[0], dp[1], dp[2]});
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
