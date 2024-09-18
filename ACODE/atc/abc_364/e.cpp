#include <bits/stdc++.h>
using i64 = long long;
constexpr int inf = 0x3f3f3f3f;

void solve() { 
    int N, X, Y;
    std::cin >> N >> X >> Y;

    // 考虑 dp[i][j][k] 当前处理到第i个 吃了j个 甜度为k的时候 咸度的最小值
    std::vector dp(N + 1, std::vector(X + 1, inf));
    dp[0][0] = 0;
    for (int i = 0; i < N; ++i) {
        int a, b;
        std::cin >> a >> b;
        std::vector ndp(N + 1, std::vector(X + 1, inf));
        for (int j = 0; j <= N; ++j) {
            for (int k = 0; k <= X; ++k) {
                ndp[j][k] = dp[j][k];
                if (j and k >= a and dp[j - 1][k - a] + b <= Y) {
                    ndp[j][k] = std::min(ndp[j][k], dp[j - 1][k - a] + b);
                }
            }
        }
        dp.swap(ndp);
    }

    int ans = 0;
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= X; ++j) {
            if (dp[i][j] <= Y) {
                // 求的是超过 这时还可以再吃一个
                ans = std::max(ans, i + 1);
            }
        }
    }

    ans = std::min(ans, N);
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(0),std::cin.tie(0);
    
    solve();

    return 0;
}