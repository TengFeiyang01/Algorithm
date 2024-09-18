#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	int ans = 0;
	for (int i = 0, x; i < n; ++i) {
		std::cin >> x;
		int a, b, c;
		a = x >= 500 ? x - x / 10 : x;
		b = x >= 1000 ? x - 150 : x;
		c = x == 1111 ? 0 : x - x / 20;
		ans += std::min({a, b, c});
	}
	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
