#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 2>> seg(n);
    std::vector<int> dp(n + 1);

    for (auto &[l, r] : seg) std::cin >> l >> r;
    std::sort(seg.begin(), seg.end());
	
	for (int i = 0; i < n; ++i) {
		if (i) dp[i] = std::max(dp[i], dp[i - 1]);
		for (int j = i + 1; j < n; ++j) {
			if (seg[i][1] >= seg[j][0]) {
				int k = std::lower_bound(seg.begin(), seg.end(), std::array<int, 2>({1 + std::max(seg[i][1], seg[j][1]), 0})) - seg.begin();
				dp[k] = std::max(dp[k], dp[i] + 2);
			} else {
				break;
			}
		}
	}
	//所有位置都会转移到dp[n]
	std::cout << n - dp.back() << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
