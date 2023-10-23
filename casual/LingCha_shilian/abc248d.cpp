#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, q, l, r, x;
    std::cin >> n;
    std::vector<int> a(n), c(n + 1);
    for (int &x : a) std::cin >> x;
    std::cin >> q;
	std::vector ld(n + 1, std::vector<std::pair<int, int>>());
	std::vector rd(n + 1, std::vector<std::pair<int, int>>());
	std::vector<int> ans(q);
	for (int i = 0; i < q; ++i) {
		std::cin >> l >> r >> x;
		if (l - 2 >= 0)
			ld[l - 2].emplace_back(x, i);
		rd[r - 1].emplace_back(x, i);
	}

	for (int i = 0; i < n; ++i) {
		int v = a[i];
		c[v] += 1;
		for (auto[x, j] : ld[i]) {
			ans[j] -= c[x];
		}
		for (auto[x, j] : rd[i]) {
			ans[j] += c[x];
		}
	}
	for (int i = 0; i < q; ++i) {
		std::cout << ans[i] << "\n";
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}