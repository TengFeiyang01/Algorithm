#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n, k;
    std::cin >> n >> k;

    std::vector<i64> a(n);
    i64 l = (k + 1) / 2, s = 0, r = k / 2, ans = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        s += a[i];
    }
    
    if (k >= s) {
        std::cout << n << "\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (l >= a[i]) {
            l -= a[i];
            ans++;
        } else {
            break;
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        if (a[i] <= r) {
            r -= a[i];
            ans++;
        } else {
            break;
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
