#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    if (k == 1) {
    	std::cout << 1 << "\n";
    } else if (k == 2) {
        if (m <= n) {
            std::cout << m << "\n";
            return;
        }
        std::cout << n + m / n - 1 << "\n";
    } else if (k == 3) {
        if (m <= n) {
            std::cout << 0 << "\n";
            return;
        }
        std::cout << (1LL * m - n) / n * (n - 1) + (m - n) % n << "\n";
    } else {
        std::cout << 0 << "\n";
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