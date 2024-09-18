#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector dp(n, std::vector(n, inf));
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	dp[i][i] = 1;
        if (i) dp[i - 1][i] = 1 + (a[i] != a[i - 1]);
    }

    for (int i = n - 3; i >= 0; --i) {
    	for (int j = i + 2; j < n; ++j) {
    		if (a[i] == a[j]) {
    			dp[i][j] = dp[i + 1][j - 1];
    		} 
    		for (int k = i; k < j; ++k) {
    			dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k + 1][j]);
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
