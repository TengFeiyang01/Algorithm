#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector dp(31, 0);
    for (int i = 0; i < n; ++i) {
        int x, mx = 0;
        std::cin >> x;
        for (int j = 0; j < 30; ++j) {
            if (x >> j & 1) {
                mx = std::max(mx, dp[j] + 1);
            }
        }
        for (int j = 0; j < 30; ++j) {
            if (x >> j & 1) {
                dp[j] = mx;
            }
        }
    }
    std::cout << std::ranges::max(dp) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
