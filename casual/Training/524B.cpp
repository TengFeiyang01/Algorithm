#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::array<int, 2>> a(n);
	int mx_h = 0, mn_h = 123312;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i][0] >> a[i][1];
		mx_h = std::max({mx_h, a[i][0], a[i][1]});
		mn_h = std::min({mn_h, a[i][0], a[i][1]});
	}
	i64 ans = 1e18;
	for (int i = mx_h; i >= mn_h; --i) {
		bool ok = true;
		i64 w = 0;
		for (int j = 0; j < n; ++j) {
			int p = std::min(a[j][0], a[j][1]);
			int q = a[j][0] ^ a[j][1] ^ p;
			if (p > i) {
				ok = false;
				break;
			}
			if (q > i) w += q;
			else w += p;
		}
		if (ok) {
			ans = std::min(ans, 1LL * i * w);
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