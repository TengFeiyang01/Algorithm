#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k, x, y;
    std::cin >> n >> k >> x >> y;
    if (n <= k) {
    	std::cout << n * x << "\n";
    } else {
    	std::cout << k * x + (n - k) * y << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
