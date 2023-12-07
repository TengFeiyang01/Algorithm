#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector dp(n + 1, std::vector<i64>(n + 1, 1e15));
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
    	std::vector<int> a(m + 1);
    	for (int j = 1; j <= m; ++j) {
    		std::cin >> a[j];
    	}

    	std::sort(a.begin() + 1, a.end());
    	for (int j = 1; j <= m; ++j) {
    		a[j] += a[j - 1];
    	}

		for (int j = i; j <= n; ++j) {
			for (int k = 0; k <= std::min(n - j, m); ++k) {
    			dp[i + 1][j + k] = std::min(dp[i + 1][j + k], dp[i][j] + a[k] + k * k);
			}
		}    	
    }
    std::cout << dp[n][n] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
