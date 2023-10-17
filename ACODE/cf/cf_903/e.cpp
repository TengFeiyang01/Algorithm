#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::vector<std::array<int, 2>> dp(n + 2);
    for (int i = n - 1; i >= 0; --i) {
    	if (i + a[i] + 1 <= n) {
    		dp[i][0] = std::min(n - 1 - i - a[i], std::min(dp[i + a[i] + 1][0], dp[i + a[i] + 1][1]));
    	} else {
            dp[i][0] = inf;
        }
    	dp[i][1] = std::min(dp[i + 1][0], dp[i + 1][1]) + 1;
    }
    
    std::cout << std::min(dp[0][0], dp[0][1]) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}