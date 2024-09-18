#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int h1, m1, h2, m2, c, n;
    scanf("%d:%d %d:%d %d", &h1, &m1, &h2, &m2, &n);
    int tot = (h2 - h1) * 60 + (m2 - m1);

    std::vector<int> dp(tot + 1);
    for (int i = 0; i < n; ++i) {
        int v, w, s;
        scanf("%d%d%d", &v, &w, &s);
        if (s == 0) {
            for (int j = v; j <= tot; ++j) {
                dp[j] = std::max(dp[j], dp[j - v] + w);
            }
        } else if (s == 1) {
            for (int j = tot; j >= v; --j) {
                dp[j] = std::max(dp[j], dp[j - v] + w);
            }
        } else {
            auto f = dp;
            for (int r = 0; r < v; ++r) {
                std::deque<int> q;
                for (int j = r; j <= tot; j += v) {
                    while (q.size() and j - s * v > q.front()) q.pop_front();
                    // 单调队列优化
                    if (q.size()) dp[j] = std::max(f[j], f[q.front()] + (j - q.front()) / v * w);
                    while (q.size() and f[q.back()] + (j - q.back()) / v * w <= f[j]) q.pop_back();
                    q.push_back(j);
                }            
            }
        }
    }
    std::cout << dp[tot] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
