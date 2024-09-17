#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    int B, M;
    std::cin >> B >> M;
    
    int dp[n + 1][M + 1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= M; ++j) {
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= M; ++j) {
            // 不使用地铁的情况
            dp[i][j] = dp[i - 1][j] + a[i];
            if (j > 0) {
                // 使用地铁的情况，尝试跳跃k个点
                for (int p = i - 1; p >= std::max(0, i - k); --p) {
                    dp[i][j] = std::min(dp[i][j], dp[p][j - 1] + B * (i - p));
                }
            }
        }
    }
    
    int ans = inf;
    for (int i = 0; i <= M; ++i) {
        ans = std::min(ans, dp[n][i]);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
