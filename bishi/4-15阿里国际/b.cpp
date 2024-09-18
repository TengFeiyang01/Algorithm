#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][0] >> a[i][1];
    }

    auto dfs = [&](int l, int r) {
        std::vector<std::array<i64, 3>> dp(n + 1);
        for (int i = l; i <= r; ++i) {
            auto [x, y] = a[i - 1];
            dp[i][0] = dp[i - 1][1] + x;
            dp[i][1] = dp[i - 1][0] + y;
        }
        return std::max(dp[r][0], dp[r][1]);
    };

    std::cout << std::max(dfs(1, n - 1), dfs(2, n)) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
