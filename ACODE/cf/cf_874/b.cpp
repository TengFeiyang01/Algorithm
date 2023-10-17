#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < n; ++i) std::cin >> b[i];

    std::vector<int> id(n);
	std::iota(id.begin(), id.end(), 0);
    std::sort(b.begin(), b.end());
	std::sort(id.begin(), id.end(), [&](auto x, auto y) {
		return a[x] < a[y];
	} );
    
    std::vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[id[i]] = b[i];
    }

	for (int i = 0; i < n; ++i) {
		std::cout << ans[i] << " \n"[i == n - 1];
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
