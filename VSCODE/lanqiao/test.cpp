#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        a[i] ^= a[i - 1];
    }

    std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(k + 1));
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= std::min(i, k); ++j) {
    //         if (j == 1)  {
    //             dp[i][j] = a[i];
    //         } else {
    //             for (int p = j - 1; p < i; ++p) {
    //                 dp[i][j] = std::max(dp[i][j], dp[p][j - 1] + (a[p - 1] ^ a[i]));
    //             }
    //         }
    //     }
    // }

    for (int j = 1; j <= k; ++j) {
        std::cout << "j：" << j << "\n";
        for (int i = j; i <= n; ++i) {
            std::cout << "    i: " << i << "\n";
            for (int p = j - 1; p < i; ++p) {
                std::cout << "      p: " << p << "[" << i << "]" << "[" << j << "]" << "<-[" << p << "]" << "[" << j - 1 << "]" << "\n";
                dp[i][j] = std::max(dp[i][j], dp[p][j - 1] + (a[p] ^ a[i]));
            }
        }
    }

    std::cout << dp[n][k];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
