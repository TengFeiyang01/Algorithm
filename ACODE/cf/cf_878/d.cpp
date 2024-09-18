#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x : a) std::cin >> x;
    int l = 0, r = 200000001;

	std::sort(a.begin(), a.end());

	while (l < r) {
		int mid = (l + r) >> 1;

		bool ok = false;
		int p = 0;
		for (int j = 0; j < 3; ++j) {
			p = std::upper_bound(a.begin(), a.end(), a[p] + 2 * mid) - a.begin();
			if (p == n) {
				ok = true;
				break;
			}
		}

		if (ok) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	std::cout << l << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
