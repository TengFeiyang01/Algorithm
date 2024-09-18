#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::map<int, i64> cnt;
	for (int i = 0; i < n; ++i) {
		int x, y;
		std::cin >> x >> y;
		cnt[x] += y;
	}
	std::vector<int> ans;
	for (auto &[k, v] : cnt) {
		if (v >= 2) {
			cnt[k + 2] += v / 2;
		}
		v %= 2;
		if (v % 2) {
			ans.push_back(k);
		}
	}

	std::cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); ++i) {
		std::cout << ans[i] << " \n"[i == ans.size() - 1];
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}