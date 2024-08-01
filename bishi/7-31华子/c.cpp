#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::array<int, 2>> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i][0] >> a[i][1];
	}
	std::sort(a.begin(), a.end());

	int mx = 0;
	std::vector<std::array<int, 2>> seg;
	for (auto x : a) {
		int l = x[0], r = x[1];
		if (seg.empty() or seg.back()[1] < l) {
			seg.push_back(std::array<int, 2>{l, r});
		} else {
			seg.back()[1] = std::max(seg.back()[1], r);
		}
		mx = std::max(mx, seg.back()[1] - seg.back()[0] + 1);
	}

	std::vector<std::vector<int>> f(110, std::vector<int>(110, inf));
	for (auto [l, r] : a) {
		for (int i = l; i <= r; ++i) {
			for (int j = i; j <= r; ++j) {
				f[i][j] = 1;
			}
		}
	}

	for (int len = 1; len <= 101; ++len) {
		for (int l = 0; l + len - 1 <= 100; ++l) {
			int r = l + len - 1;
			for (int k = l + 1; k <= r; ++k) {
				f[l][r] = std::min(f[l][r], f[l][k] + f[k][r]);
			}
		}
	}
	std::cout << mx << "\n";

	int ans = inf;
	for (int i = 0; i + mx - 1 <= 100; ++i) {
		ans = std::min(ans, f[i][i + mx - 1]);
	}
	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
