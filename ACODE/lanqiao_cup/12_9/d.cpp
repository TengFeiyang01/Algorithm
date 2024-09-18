#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        s[i] = a[i] + s[i - 1];
    }
    i64 ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += a[i] * (s[n] - s[i + 1]);
    }

    std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
