#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	i64 n;
	std::cin >> n;
	i64 x = i64(std::sqrt(2LL * n));
	if (x * (x + 1) / 2 > n) --x;
	if (x * (x + 1) / 2 == n) {
		std::cout << x + 1 << "\n";
	} else {
		i64 p = n - x * (x + 1) / 2;
		std::cout << x + p + 1 << "\n";
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