#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(n);
    a[0] = 0;
    for (int i = 1; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];

    }

    std::ranges::sort(a);
    std::ranges::sort(b);
    a.push_back(inf);

    int l = 1, r = 0;
    int mx = 0, cnt = 0;
    while (r < n) {
        if (a[l] >= b[r]) {
            mx = std::max(mx, b[r++]);
        } else {
            l++, r++;
        }
    }

    if (m >= mx) {
        cnt = mx - 1;
    } else {
        cnt = m;
    }

    i64 ans = i64(m) * i64(n - l + 1LL) - cnt;

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