#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, x;
    std::cin >> n >> x;
    --x;
    std::vector<std::array<int, 2>> a(n);
    std::vector<int> sum(n + 1);
    std::vector dp(n, std::vector(n, std::vector(2, inf)));
    dp[x][x][0] = dp[x][x][1] = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][0] >> a[i][1];
    	sum[i + 1] = sum[i] + a[i][1];
    }
    for (int i = n - 2; i >= 0; --i) {
    	for (int j = i + 1; j < n; ++j) {
    		dp[i][j][0] = std::min(dp[i + 1][j][0] + (a[i + 1][0] - a[i][0]) * (sum[n] - sum[j + 1] + sum[i + 1]),
    							   dp[i + 1][j][1] + (a[j][0] - a[i][0]) * (sum[n] - sum[j + 1] + sum[i + 1]));
    		dp[i][j][1] = std::min(dp[i][j - 1][1] + (a[j][0] - a[j - 1][0]) * (sum[n] - sum[j] + sum[i]),
    							   dp[i][j - 1][0] + (a[j][0] - a[i][0]) * (sum[n] - sum[j] + sum[i]));
    	}
    }
    std::cout << std::min(dp[0][n - 1][0], dp[0][n - 1][1]);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
