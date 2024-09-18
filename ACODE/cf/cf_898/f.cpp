#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n), h(n);
	std::vector<i64> s(n), r(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		s[i] = a[i];
		if (i) s[i] += s[i - 1];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> h[i];
		r[i] = i;
	}
	
	for (int i = n - 2; i >= 0; --i) {
		if (h[i] % h[i + 1] == 0) {
			r[i] = r[i + 1];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int pre = (i ? s[i - 1] : 0);
		int p = std::upper_bound(s.begin() + i, s.begin() + r[i] + 1, k + pre) - s.begin();
		p--;
		ans = std::max(ans, p - i + 1);
	}
	std::cout << ans << "\n";
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