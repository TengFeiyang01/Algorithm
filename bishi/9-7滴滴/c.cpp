#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::vector<std::vector<int>> cost(k, std::vector<int>(k));
    for (int i = 0; i < k; ++i) {
    	for (int j = 0; j < k; ++j) {
    		std::cin >> cost[i][j];
    	}
    }
    std::cin >> s;
    auto get = [&](char x, char y) {
    	return cost[x - 'a'][y - 'a'];
    };
    std::vector<std::vector<int>> dp(n, std::vector<int>(n));

    for (int len = 2; len <= n; len += 2) {
    	for (int i = 0; i + len - 1 < n; ++i) {
    		int j = i + len - 1;
    		for (int k = i + 1; k < j; k += 2) {
    			dp[i][j] = std::max(dp[i][j], dp[i][k] + dp[k + 1][j]);
    		}
    		dp[i][j] = std::max(dp[i][j], dp[i + 1][j - 1] + get(s[i], s[j]));
    	}
    }
    std::cout << dp[0][n - 1];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
