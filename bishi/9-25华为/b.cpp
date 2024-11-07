#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;


void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<i64> a(n + 1), s(n + 1), g(n + 1), sg(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        s[i] = a[i] + s[i - 1];
        g[i] = std::__gcd(a[i], a[i - 1]);
        sg[i] = sg[i - 1] + g[i];
    }
    i64 ans = -1;
    for (int i = 1; i <= n; ++i) {
        int l = i, r = n;
        while (l < r) {
            int mid = 1 + l + r >> 1;
            if (s[mid] - s[i - 1] <= k) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (l >= i and s[l] - s[i - 1] <= k) {
            ans = std::max(ans, sg[l] - sg[i]);
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
