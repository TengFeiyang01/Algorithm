#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<i64> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	auto check = [&](i64 x) {
		i64 cnt = 1, p = a[0], s = 0;
		for (int i = 1; i < n; ++i) {
			if (s + a[i] * p <= x) {
				s += a[i] * p;
				p += a[i];
			} else {
				cnt++;
				s = 0;
				p = a[i];
			}
		}		
		return cnt <= m;
	};
	
	i64 l = 0, r = 3e18;
	while (l < r) {
		i64 mid = l + r >> 1;
		if (check(mid)) {
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
    
    solve();

    return 0;
}
