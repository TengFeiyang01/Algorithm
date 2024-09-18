#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    int ans = 0;
    int i = 0, n = s.size();
    std::vector<int> dp(n);
    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
    	if (s[i] == s[i - 1]) {
    		dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
    	}
    	ans = std::max(ans, dp[i]);
    }
    std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
