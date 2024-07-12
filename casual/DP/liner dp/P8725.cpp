#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int mod = 1e9+7;

void solve() {
	int d, n, m;
	std::cin >> d >> n >> m;
	std::vector dp(n + 1, std::vector<i64>(m + 2));
	dp[0][m] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (d + (m - j) - (i - (m - j))) {
				dp[i][j] = (dp[i - 1][j] + dp[i - 1][j + 1]) % mod;
			}
		}
	}
	std::cout << dp[n][0] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
