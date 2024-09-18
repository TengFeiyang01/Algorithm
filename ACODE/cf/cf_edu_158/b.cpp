#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = n - 1; i > 0; --i) a[i] -= a[i - 1];
    i64 ans = 0, pos = 0, neg = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0) {
            pos += a[i];
        } else {
            neg -= a[i];
        }
    }
    ans = std::max(pos, neg) - 1;
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
