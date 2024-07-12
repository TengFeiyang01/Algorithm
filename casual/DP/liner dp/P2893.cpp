#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    auto b = a;
    std::ranges::sort(b);
    b.erase(std::unique(b.begin(), b.end()), b.end());
    int m = b.size();
    std::vector dp(n + 1, std::vector(n + 1, 0LL));
    std::vector f(n + 1, std::vector(n + 1, 0LL));

    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= m; ++j) {
    		dp[i][j] = f[i - 1][j] + std::abs(a[i - 1] - b[j - 1]);
    		if (j == 1) {
    			f[i][j] = dp[i][j];
    		} else {
    			f[i][j] = std::min(f[i][j - 1], dp[i][j]);
    		}
    	}
    }
    i64 ans = f[n][m];
    std::ranges::reverse(b);
    dp = std::vector(n + 1, std::vector(n + 1, 0LL));
    f = std::vector(n + 1, std::vector(n + 1, 0LL));

    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= m; ++j) {
    		dp[i][j] = f[i - 1][j] + std::abs(a[i - 1] - b[j - 1]);
    		if (j == 1) {
    			f[i][j] = dp[i][j];
    		} else {
    			f[i][j] = std::min(f[i][j - 1], dp[i][j]);
    		}
    	}
    }
    ans = std::min(ans, f[n][m]);
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
	