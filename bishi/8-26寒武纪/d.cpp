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
    int ans = inf;
    if (n <= 2) {
    	std::cout << 0;
    	return;
    }
    std::unordered_map<double, int> dp[200002];
    for (int i = 1; i < n; ++i) {
    	for (int j = 0; j < i; ++j) {
    		double d = 1.0 * (a[i] - a[j]) / (i - j);
    		dp[i][d] = std::max(dp[i][d], 2);
    		if (dp[j].count(d)) dp[i][d] = std::max(dp[i][d], dp[j][d] + 1);
    		ans = std::max(ans, dp[i][d]);
    	}
    }
    std::cout << n - ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
