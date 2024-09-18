#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, l, r;
    std::cin >> n >> l >> r;
    std::vector<i64> dp(n + 1, -inf);
    std::vector<i64> a(n + 1);
    for (i64 i = 0; i <= n; ++i) {
        std::cin >> a[i];
    }
    // i+r >= now
    // i+l <= now
    // now-r <= i <= now - l
    std::deque<int> q;
    dp[0] = 0;
    i64 ans = -1e15;
    for (i64 i = l; i <= n; ++i) {
        while (q.size() and dp[q.back()] <= dp[i - l]) q.pop_back();
        q.push_back(i - l);
        while (q.front() < i - r) q.pop_front();
        dp[i] = dp[q.front()] + a[i];
        if (i + r > n) {
            ans = std::max(ans, dp[i]);
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}


