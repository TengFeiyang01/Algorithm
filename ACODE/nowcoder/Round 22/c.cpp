#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	i64 n, k, x;
	std::cin >> n >> k >> x;
	if (k < n) {
		std::cout << "-1\n";
		return;
	}
	i64 tot = (1LL + n) * n / 2;
	if (tot > x) {
		std::cout << "-1\n";
		return;
	}

	std::vector<i64> a(n);
	std::iota(a.begin(), a.end(), 1LL);
	i64 mx = k;
	x -= (1LL + n) * n / 2;
	
	for (int i = n - 1; i >= 0; --i, --mx) {
		i64 d = mx - a[i];
		if (x >= d) {
			x -= d;
			a[i] += d;
		} else {
			a[i] += x;
			x = 0;
			break;
		}
	}
	i64 s = 0;
	if (x > 0) {
		std::cout << "-1\n";
		return;
	}

	for (int i = 0; i < n; ++i) {
		std::cout << a[i] << " \n"[i == n - 1];
	}

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
