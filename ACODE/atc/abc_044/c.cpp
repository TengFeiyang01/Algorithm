#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, A;
    std::cin >> n >> A;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::vector dp(n + 1, std::vector(n + 1, std::vector<i64>(2550)));
    i64 ans = 0;
    dp[0][0][0] = 1;
    //枚举总和 dp[i][j][k] 前i个数 取了j个 和是k
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= 2530; ++k) {
                if (k >= a[i] and j >= 1)
                    dp[i + 1][j][k] = dp[i][j - 1][k - a[i]] + dp[i][j][k];
                else
                    dp[i + 1][j][k] = dp[i][j][k];
            }
        }
    }

    for (int i = 1; i <= n; ++i) ans += dp[n][i][i * A];
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
