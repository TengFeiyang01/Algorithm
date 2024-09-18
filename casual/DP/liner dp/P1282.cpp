#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, s = 0;
    std::cin >> n;
    std::vector<std::array<int, 2>> a(n);
    for (auto &[x, y] : a) {
    	std::cin >> x >> y;
    	s += x + y;
    }
	std::vector dp(6 * n + 1, inf);
	dp[a[0][0]] = 0;
	dp[a[0][1]] = 1;
	for (int i = 1; i < n; ++i) {
		auto [x, y] = a[i];
		std::vector ndp(6  * n + 1, inf);
		for (int j = 0; j <= 6 * n; ++j) {
			if (j - x >= 0) ndp[j] = std::min(ndp[j], dp[j - x]);
			if (j - y >= 0) ndp[j] = std::min(ndp[j], dp[j - y] + 1);
		}
		dp = ndp;
	}
	int mnd = inf, mnt = inf;
	for (int i = 0; i <= s; ++i) {
		if (dp[i] != inf) {
			if (abs(i - (s - i)) < mnd) {
				mnd = abs(i - (s - i));
				mnt = dp[i];
			} else if (abs(i - (s - i)) == mnd) {
				mnt = std::min(mnt, dp[i]);
			}
		}
	}
	std::cout << mnt << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
