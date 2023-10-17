#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
	std::vector<std::array<int, 2>> seg(m);
	for (auto &[x, y] : seg) {
		std::cin >> x >> y;    
	}

	int q;
	std::cin >> q;
	std::vector<int> a(q);
	for (int i = 0; i < q; ++i) {
		std::cin >> a[i];
	}

	auto check = [&](int k) ->bool {
		std::vector<int> sum(n + 1);
		
		for (int i = 0; i < k; ++i) {
			sum[a[i]]++;
		}	

		for (int i = 1; i <= n; ++i) sum[i] += sum[i - 1];
		for (const auto&[x, y] : seg) {
			int one = sum[y] - sum[x - 1];
			int zero = y - x + 1 - one;
			if (one > zero) return true;
		}
		return false;
	};

	int l = 1, r = q + 1;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}

	if (l > q) l = -1;
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
