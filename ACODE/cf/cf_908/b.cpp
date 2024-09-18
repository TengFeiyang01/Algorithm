#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::map<int, std::vector<int>> pos;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		pos[a[i]].push_back(i);
	}
	int cnt = 0;
	for (auto [_, v] : pos) {
		if (v.size() >= 2) {
			cnt++;
		}
	}
	if (cnt <= 1) {
		std::cout << -1 << "\n";
	} else {
		std::vector<int> ans(n, 1);
		int t = 2, p = 2;
		for (auto [_, v] : pos) {
			if (t and v.size() >= 2) {
				ans[v[1]] = p++;
				t--;
			}
		}

		for (int i = 0; i < n; ++i) {
			std::cout << ans[i] << " \n"[i == n - 1];
		}
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
