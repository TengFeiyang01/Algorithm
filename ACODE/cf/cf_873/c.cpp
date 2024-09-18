#include <bits/stdc++.h>

using ll = long long;
const int MOD = 1000000007;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < n; ++i) std::cin >> b[i];
    std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	for (int i = 0; i < n; ++i) {
		if (a[i] <= b[i]) {
			std::cout << "0\n";
			return;
		}
	}
	ll ans = 1LL;
	for (int i = 0; i < n; ++i) {
		int x = a[i];
		int j = std::lower_bound(b.begin(), b.end(), x) - b.begin();
		ll cur = j - i + 0LL;
		ans = (ans * cur) % MOD;
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
