#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();

    std::vector dp(n, std::vector(n, inf));
    for (int i = 0; i < n; ++i) dp[i][i] = 1;
    for (int i = n - 2; i >= 0; --i) {
    	for (int j = i + 1; j < n; ++j) {
    		if (s[i] == s[j]) {
    			dp[i][j] = std::min(dp[i + 1][j], dp[i][j - 1]);
    		} else {
    			for (int k = i; k < j; ++k) {
    				dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k + 1][j]);
    			}
    		}
    	}
    }
    std::cout << dp[0][n - 1] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
