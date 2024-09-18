#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	std::map<int, int> cnt;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		cnt[a[i]] = m + 1;
	}   

	i64 ans = 0;

	for (int i = 0; i < m; ++i) {
		int pos, val;
		std::cin >> pos >> val;
		pos--;
		cnt[a[pos]] -= (m - i);
		cnt[val] += m- i;
		a[pos] = val;
	}

	for (auto &[x, v] : cnt) {
		ans += 1LL * (v - 1) * v / 2;
		ans += 1LL * v * (m + 1 - v);
	}
	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
