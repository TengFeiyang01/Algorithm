#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int x, y, z;
    std::cin >> x >> y >> z;
   	if (x >= y) {
   		std::cout << x << "\n";
   	} else {
   		int d = y - x;
   		std::cout << y + std::max(0, d - z) << "\n";
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
