#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int x, y, n;
	std::cin >> x >> y >> n;
	std::vector<i64> a(n);
	a[n - 1] = y;
	for (int i = n - 2, t = 1; i >= 0; --i, ++t) {
		a[i] = a[i + 1] - t;
	}
	if (a[0] >= x) {
		a[0] = x;
		for (int i = 0; i < n; ++i) {
			std::cout << a[i] << " \n"[i == n - 1];
		}
	} else {
		std::cout << "-1\n";
	}

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