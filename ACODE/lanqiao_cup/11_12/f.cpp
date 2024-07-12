#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	i64 n, k, x, y;
	std::cin >> n >> k;
	
	auto calc = [&](i64 N, i64 K) {
		i64 l = 1, r = N;
		while (l < r) {
			i64 mid = l + r >> 1;
			if (mid * (mid + 1) >= 2 * K) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		K -= (r - 1) * r / 2;
		x = K, y = l - K + 1;
	};

	if (2 * k <= n * (n + 1)) {
		calc(n, k);
	} else {
		k = n * n - k + 1;
		calc(n, k);
		x = n - x + 1, y = n - y + 1;
	}
	std::cout << x << " " << y << "\n";
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
