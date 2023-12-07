#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

// 令 dp[i][j] 为前 i 个数 凑成数字 j 最小操作次数
void solve() {
	int m, n;
	std::string s;
	std::cin >> s >> m;
	n = s.size();

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		a[i] = s[i - 1] - '0';
	}

	std::vector num(n + 1, std::vector<i64>(n + 1));
	
	for (int i = 1; i <= n; ++i) {
		num[i][i] = a[i];
		for (int j = i; j - i <= 6 and j <= n; ++j) {
			num[i][j] = num[i][j - 1] * 10 + a[j];
		}
	}
	std::vector dp(n + 1, std::vector<int>(m + 1, inf));
	dp[0][0] = 0;
	for (int i = 1;i <= n; ++i) {
		for (int k = 1; k <= std::min(i, 6); ++k) {
			for (i64 j = num[i - k + 1][i]; j <= m; ++j) {
				dp[i][j] = std::min(dp[i][j], dp[i - k][j - num[i - k + 1][i]] + 1);
			}
		}
	}
	if (dp[n][m] > n) {
		std::cout << "-1\n";
	} else {
		std::cout << dp[n][m] - 1 << "\n";
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
