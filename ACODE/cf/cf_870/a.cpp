#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);

	for (int i = 0; i < n; ++i) std::cin >> a[i];

	int ans = -1;
	for (int cnt = 0; cnt <= n; ++cnt) {
		int cur = 0;
		for (int num : a) {
			if (num > cnt) cur++;
		}
		if (cur == cnt) {
			std::cout << cnt << "\n";
			return;
		}
	}
	std::cout << -1 << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
