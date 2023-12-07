#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<i64> a, b;
    i64 sum = 0;

    for (int i = 1; i <= n; ++i) {
    	int ty, x;
    	std::cin >> ty >> x;
    	if (ty == 2) {
    		if (b.size() < a.size()) {
    			b.push_back(sum);
    		}
    		a.push_back(x);
    		sum = 0;
    	} else {
    		sum += x;
    	}
    }
    n = a.size();
    std::vector dp(n, std::vector(k + 1, std::vector<i64>(2, -1e18)));
    for (int i = 0; i < n; ++i) {
    	dp[i][0][0] = 0;
    	for (int j = 1; j <= k; ++j) {
    		if (i) dp[i][j][0] = std::max(dp[i - 1][j][0], dp[i - 1][j][1]);
    		else dp[i][j][0] = 0;

    		if (i >= 1 and j >= a[i] + a[i - 1]) {
    			dp[i][j][1] = std::max((i == 1 ? 0 : dp[i - 2][j - a[i] - a[i - 1]][0]) + b[i - 1],
    									(i == 1 ? 0 : dp[i - 2][j - a[i] - a[i - 1]][1] + b[i - 1] + b[i - 2]));
    		}
    	}
    }
    i64 ans = 0;
    for (int j = 0; j <= k; ++j) {
    	ans = std::max({ans, dp[n - 1][j][0], dp[n - 1][j][1]}); 
    }
    std::cout << ans << "\n";
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
