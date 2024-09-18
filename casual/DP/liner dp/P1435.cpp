#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    
    std::vector dp(n, std::vector<int>(n));
    // dp[i+1][j] 代表的是给 s[i] 新增一个匹配的 
    for (int i = n - 2; i >= 0; --i) {
    	for (int j = i + 1; j < n; ++j) {
    		if (s[i] == s[j]) {
    			dp[i][j] = dp[i + 1][j - 1];
    		} else {
    			dp[i][j] = std::min(dp[i + 1][j], dp[i][j - 1]) + 1;
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
