#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n / 2; ++i) {
    	for (int j = 1; j <= m; ++j) {
    		std::cout << i << " " << j << "\n";
    		std::cout << n - i + 1 << " " << m - j + 1 << "\n";
    	}
    }
    if (n & 1) {
    	for (int j = 1; j < m / 2; ++j) {
    		std::cout << n << " " << j << "\n";
    		std::cout << n << " " << m - j + 1 << "\n";
    	}
    	if (m & 1) {
    		std::cout << n << " " << (m + 1) / 2 << "\n";
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}