#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = unsigned long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    i64 n, c;
    std::cin >> n >> c;
    std::vector<i64> a(n);
    for (auto &x : a) std::cin >> x;
    i64 l = 0, r = 1e9;
	
	auto check = [&](i64 k) {
		i64 cur = 0;
		for (int i = 0; i < n; ++i) {
			cur += (a[i] + 2 * k) * (a[i] + 2 * k);
			if (cur > c) return false;
		}
		return cur <= c;
	};

	while (l < r) {
		i64 mid = l + r + 1 >> 1;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	std::cout << l << "\n";
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
