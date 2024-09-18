#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int mod = 1e9+7;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    std::vector<std::vector<int>> dp(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
    		std::cin >> a[i][j];
    	}
    }
    dp[0][0] = 1;
    for (int i = 1; i < n && a[0][i]; ++i) {
    	dp[0][i] = 1;
    }
    for (int i = 1; i < n && a[i][0]; ++i) {
    	dp[i][0] = 1;
    }
    for (int i = 1; i < n; ++i) {
    	for (int j = 1; j < n; ++j) {
    		if (a[i][j]) {
    			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
    		}
    	}
    }
    std::cout << dp.back().back();
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}