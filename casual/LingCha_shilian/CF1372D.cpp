#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    for (i64 i = 2; i * i <= n; ++i) {
    	if (n % i == 0) {
    		std::cout << n / i << " " << n - n / i << "\n";
    		return; 
    	}
    }
    std::cout << 1 << " " << n - 1 << "\n";
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
