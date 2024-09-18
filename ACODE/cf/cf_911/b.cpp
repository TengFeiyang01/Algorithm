#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	std::array<int, 3> a;
	for (int i = 0; i < 3; ++i) {
		std::cin >> a[i];
		a[i] %= 2;
	}
	for (int i = 0; i < 3; ++i) {
		if (a[(i + 1) % 3] == a[(i + 2) % 3]) {
			std::cout << 1 << " ";
		} else {
			std::cout << 0 << " ";
		}
	}
	std::cout << "\n";
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
