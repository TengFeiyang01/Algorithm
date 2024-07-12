#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][0] >> a[i][1];
    }
    std::vector dp(n, std::vector<i64>(3, 1e18));
    dp[0][0] = 0;
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][1] * 2;
    for (int i = 1; i < n; ++i) {
    	for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (a[i - 1][0] + j != a[i][0] + k) {
                    dp[i][k] = std::min(dp[i][k], dp[i - 1][j] + k * a[i][1]);
                }
            }
        }
    }
    std::cout << std::min(dp[n - 1][0], dp[n - 1][1]) << "\n";
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
