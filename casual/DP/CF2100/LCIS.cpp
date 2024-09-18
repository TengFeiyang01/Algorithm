#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
    	std::cin >> b[i];
    }

    std::vector dp(n + 1, std::vector(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
    	int mx = 0;
    	for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                if (dp[i][j] < mx + 1) {
                    dp[i][j] = mx + 1;
                } 
    		} else {
                dp[i][j] = dp[i - 1][j];
            }
    		if (b[j - 1] < a[i - 1]) {
                mx = std::max(mx, dp[i - 1][j]);
            }
    	}
    }
    std::cout << *std::max_element(dp.back().begin(), dp.back().end());
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
