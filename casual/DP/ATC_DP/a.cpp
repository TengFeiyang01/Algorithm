#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    // std::vector<int> dp(n);
    // dp[1] = abs(a[1] - a[0]);
    // for (int i = 2; i < n; ++i) {
    //     dp[i] = std::min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2]));
    // }
    int s = 0, f = abs(a[1] - a[0]);
    for (int i = 2; i < n; ++i) {
        int t = std::min(f + abs(a[i] - a[i - 1]), s + abs(a[i] - a[i - 2]));
        s = f;
        f = t;
    }
    std::cout << f << "\n";
    // std::cout << dp.back();
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
