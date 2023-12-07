#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    i64 s = 0, ans = -1e14;
    std::vector<i64> a(n + 1), pre(n + 1, -1e15);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        s += a[i];
        if (i >= k) {
            s -= a[i - k];
            pre[i] = std::max(pre[i - 1], s);
            ans = std::max(ans, pre[i - k] + s);
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
