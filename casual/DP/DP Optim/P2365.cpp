#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n, s;
    std::cin >> n >> s;
    std::vector<i64> t(n + 1), f(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> t[i] >> f[i];
        t[i] += t[i - 1];
        f[i] += f[i - 1];
    }
    std::vector<i64> dp(n + 1);
    // dp[i] = min{ dp[j] + s * (sumf[n] - sumf[j]) + (sumf[i] - sumf[j]) * sumt[i]}
    // dp[i] = min{ dp[j] + s * sumf[n] - s * sumf[j] + sumt[i] * sumf[i] - sumf[j] * sumt[i]}
    // dp[i] = min{ dp[j] - (s + sumt[i]) * sumf[j]} + s * sumf[n] + sumt[i] * sumf[i]
    // k = s + sumt[j]   y === -k * sumf[i] + dp[j]  过 (sumf[i], dp[j]) 的点 
    // 直线与y轴的交点是 b = dp[j] - k * sumf[j] 最小截距

    std::vector<int> q(n + 1);
    int hh = 1, tt = 1;
    for (int i = 1; i <= n; ++i) {
        // y1 - y2 <= k * (x1 - x2)
        while (hh < tt and dp[q[hh + 1]]- dp[q[hh]] <= (s + t[i]) * (f[q[hh + 1]] - f[q[hh]])) ++hh;
        dp[i] = dp[q[hh]] + t[i] * f[i] + s * f[n] - f[q[hh]] * (s + t[i]);
        while (hh < tt and (dp[i] - dp[q[tt]]) * (f[q[tt]] - f[q[tt - 1]]) <= (dp[q[tt]] - dp[q[tt - 1]]) * (f[i] - f[q[tt]])) tt--;
        q[++tt] = i;
    }
    std::cout << dp[n] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}