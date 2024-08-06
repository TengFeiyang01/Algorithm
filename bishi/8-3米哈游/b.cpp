#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<int> w(n), v(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> w[i] >> v[i];
	}
	std::unordered_set<int> ban;
	for (int i = 0; i < k; ++i) {
		int x, y;
		std::cin >> x >> y;
		--x, --y;
		ban.insert((1 << x) | (1 << y));
	}
	i64 ans = 0;
	for (int i = 1; i < 1 << n; ++i) {
		bool ok = true;
		for (auto x : ban) {
			if ((i & x) == x) {
				ok = false;
			}
		}		
		if (!ok) continue;
		i64 x = 0, y = 0;
		for (int j = 0; j < n; ++j) {
			if (i >> j & 1) {
				x += w[j];
				y += v[j];
			}
		}
		if (x <= m) {
			ans = std::max(ans, y);
		}
	}
	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
