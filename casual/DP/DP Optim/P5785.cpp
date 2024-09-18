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
    std::vector<i64> dp(n + 1), q(n + 2);
    int tt = 1, hh = 1;
    
    // 维护下凸包 单调栈二分
    for (int i = 1; i <= n; ++i) {
        int l = hh, r = tt;
        while (l < r) {
            int mid = l + r >> 1;
            if (dp[q[mid + 1]] - dp[q[mid]] > (s + t[i]) * (f[q[mid + 1]] - f[q[mid]])) r = mid;
            else l = mid + 1;
        }
    	dp[i] = dp[q[l]] + t[i] * f[i] + s * f[n] - f[q[l]] * (s + t[i]);
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
