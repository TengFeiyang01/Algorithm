#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::map<i64, std::vector<int>> mp;
	std::map<int, i64> a = {{-1, 0}, {n, 0}};
	for (int i = 0, x; i < n; ++i) {
		std::cin >> x;
		mp[a[i] = n - x].push_back(i);
	} 
	std::set<int> id{-1, n};
	std::vector<std::pair<i64, int>> vp;

	for (auto &[x, p] : mp) {
		for (int i = 0, j = 0; i < p.size(); i = j) {
			while (j < p.size() and *id.lower_bound(p[i]) > p[j]) j += 1;
			int l = *prev(id.lower_bound(p[i]));
			int r = *id.lower_bound(p[j - 1]);
			vp.emplace_back(r - l - 1, x - std::max(a[l], a[r]));
		}
		for (int i : p) id.insert(i);
	}
	i64 m, ans = 0;
	std::cin >> m;
	std::sort(vp.rbegin(), vp.rend());
	for (auto[x, y] : vp) {
		if (m >= x * y) {
			ans += (x - 1) * y;
			m -= x * y;
		} else {
			ans += m / x * (x - 1);
			ans += std::max(m % x - 1, 0LL);
			break;
		}
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
