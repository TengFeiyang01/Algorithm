#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<long double> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }

    std::vector dp(n + 1, std::vector<long double>(n + 1, -inf));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - 1] * 0.9 + a[i - 1]);
        }
    }

    std::cout << std::fixed << std::setprecision(16);
    
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
