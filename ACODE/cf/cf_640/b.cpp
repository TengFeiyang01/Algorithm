#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    if (n < k) {
        std::cout << "NO\n";
        return;
    }
    int one = n - (k - 1);
    int two = n - (2 * (k - 1));
    if (one % 2) {
        std::cout << "YES\n";
        for (int i = 0; i < k - 1; ++i) {
            std::cout << 1 << " ";
        }
        std::cout << one << "\n";
    } else if (two % 2 == 0 and two > 0) {
        std::cout << "YES\n";
        for (int i = 0; i < k - 1; ++i) {
            std::cout << 2 << " ";
        }
        std::cout << two << "\n";
    } else {
        std::cout << "NO\n";
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