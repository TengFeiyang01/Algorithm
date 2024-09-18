#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<long double> a(n);
    std::vector dp(n + 1, std::vector<long double>(n + 1));
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    } 

    //dp[i][j] 前 i 个硬币中，j 个正面的概率

    dp[0][0] = 1.0;
    for (int i = 1; i <= n; ++i) {
    	for (int j = 0; j <= i; ++j) {
            dp[i][j] = dp[i - 1][j] * (1 - a[i - 1]);
            if (j > 0) {
                dp[i][j] += dp[i - 1][j - 1] * a[i - 1];
            }
    	}
    }
    long double ans = 0;
    for (int i = n / 2 + 1; i <= n; ++i) {
    	ans += dp[n][i];
    }
    std::cout << std::setprecision(11) << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
