#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;

void solve() {
    int n;
    i64 s;
    std::cin >> n >> s;
    std::vector<i64> t(n + 1), f(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> t[i] >> f[i];
        t[i] += t[i - 1];
        f[i] += f[i - 1];
    }

    std::vector<i64> dp(n + 1);

    std::vector<int> q(n + 2);
    
    int hh = 1, tt = 1;
    for (int i = 1; i <= n; ++i) {
        //队头过期出队  y1 - y2 <= k * (x1 - x2)  保证决策点左侧小于当前斜率的出队
        //此题k并非单调 因此需要二分
        // while (hh < tt and dp[q[hh + 1]] - dp[q[hh]] <= (s + t[i]) * (f[q[hh + 1]] - f[q[hh]])) hh++;
        int l = hh, r = tt;
        while (l < r) {
            int mid = l + r >> 1;
            if ((dp[q[mid + 1]] - dp[q[mid]]) > (s + t[i]) * (f[q[mid + 1]] - f[q[mid]])) r = mid;
            else l = mid + 1;
        }
        dp[i] = dp[q[l]] + t[i] * f[i] + s * f[n] - f[q[l]] * (s + t[i]);
        //当前点以及队尾点的斜率是递增应该
        while (hh < tt and double(dp[i] - dp[q[tt]]) * (f[q[tt]] - f[q[tt - 1]]) <= double(dp[q[tt]] - dp[q[tt - 1]]) * (f[i] - f[q[tt]])) tt--;
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
