#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), p(k);
    std::vector<i64> s(n + 1);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	s[i + 1] = a[i] + s[i];
    }
    for (int i = 0; i < k; ++i) {
    	std::cin >> p[i];
    }

    std::vector dp(n + 1, std::vector<i64>(k + 1, -1e18));
    dp[0][0] = 0;


    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - 1]) + 1LL * a[i - 1] * p[j - 1];
        }
    }
    std::cout << dp[n][k] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
