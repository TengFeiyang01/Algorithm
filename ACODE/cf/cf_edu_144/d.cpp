#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 1E18;

// void solve() {
//     int n, k, x;
//     std::cin >> n >> k >> x;
    
//     std::vector<int> a(n);
//     for (int i = 0; i < n; i++) {
//         std::cin >> a[i];
//     }
    
//     std::vector dp(k + 1, std::array<i64, 3>{-inf, -inf, -inf});
//     dp[0] = {};
    
//     for (int i = 0; i < n; i++) {
//         std::vector g(k + 1, std::array<i64, 3>{-inf, -inf, -inf});
//         for (int j = 0; j <= k; j++) {
//             for (int t = 0; t < 3; t++) {
//                 g[j][t] = std::max(g[j][t], dp[j][t] + (t == 1 ? a[i] - x : 0));
//                 if (j < k) {
//                     g[j + 1][t] = std::max(g[j + 1][t], dp[j][t] + (t == 1 ? a[i] + x : 0));
//                 }
//             }
//         }
//         for (int j = 0; j <= k; j++) {
//             for (int t = 1; t < 3; t++) {
//                 g[j][t] = std::max(g[j][t], g[j][t - 1]);
//             }
//         }
//         dp = g;
//     }
    
//     auto ans = dp[k][2];
//     std::cout << ans << "\n";
// }

using ll = long long;
void solve() {
    int n, k, x;
    std::cin >> n >> k >> x;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    std::vector f(2, std::vector<ll>(k + 1, -0x3f3f3f3f3f3f3f3f));
    
    f[0][0] = 0;
 
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = std::max(0, k - n + i); j <= k && j <= i; ++j) {
            if (j < i) f[i & 1][j] = std::max(0LL, f[(i - 1) & 1][j]) + a[i] - x;
            if (j) f[i & 1][j] = std::max(f[i & 1][j], std::max(0LL, f[(i - 1) & 1][j - 1]) + a[i] + x);
            ans = std::max(ans, f[i & 1][j]);
        }
    std::cout << ans << "\n";
}



int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
