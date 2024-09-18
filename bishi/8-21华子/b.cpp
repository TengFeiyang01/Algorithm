#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n), b(n);
	int cnt1 = 0, cnt0 = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		if (a[i]) {
			cnt1++;
		} else {
			cnt0++;
		}
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> b[i];
	}
	int ans = n, res = n;
	for (int i = 0; i < n; ++i) {
		if (b[i] == 2) {
			b[i] = 1;
		}
	}
	int c1 = 0, c2 = 0;
	for (int i = 0; i < n; ++i) {
		if (b[i]) {
			c1++;
		} else {
			c2++;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (a[i]) {
			if (c1) {
				--c1;
				--ans;
			} else {
				break;
			}
		} else {
			if (c2) {
				--c2;
				--ans;
			} else {
				break;
			}
		}
	}

	c1 = 0, c2 = 0;

	auto c = b;
	for (int i = 0; i < n; ++i) {
		if (c[i] == 2) {
			c[i] = 1;
		}
		if (c[i]) {
			c1++;
		} else {
			c2++;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (a[i]) {
			if (c1) {
				--c1;
				--res;
			} else {
				break;
			}
		} else {
			if (c2) {
				--c2;
				--res;
			} else {
				break;
			}
		}
	}
	std::cout << std::min(ans, res);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
