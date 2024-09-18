#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n << 1 | 1);
    std::vector dp(n << 1 | 1, std::vector<int>(n << 1 | 1, inf));
    std::vector f(n << 1 | 1, std::vector<int>(n << 1 | 1, -inf));
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i <= 2 * n; ++i) {
        a[i] += a[i - 1];
        dp[i][i] = f[i][i] = 0;
    }

    for (int i = 2 * n - 1; i >= 1; --i) {
    	for (int j = i + 1; j <= 2 * n; ++j) {
    		for (int k = i; k < j; ++k) {
    			dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k + 1][j] + a[j] - a[i - 1]);
    			f[i][j] = std::max(f[i][j], f[i][k] + f[k + 1][j] + a[j] - a[i - 1]);
    		}
    	}
    }
    int res = inf, ans = 0;
    for (int i = 1; i <= n; ++i) {
        res = std::min(res, dp[i][i + n - 1]);
        ans = std::max(ans, f[i][i + n - 1]);
    }
    std::cout << res << "\n" << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
