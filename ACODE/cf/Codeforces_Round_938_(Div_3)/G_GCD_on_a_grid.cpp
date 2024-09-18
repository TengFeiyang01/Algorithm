#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector a(n, std::vector(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
        }
    }

    std::vector f(n, std::vector(m, 0));
    auto check = [&](int x) ->bool {
        f[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 and j == 0) continue;
                if (a[i][j] % x == 0 and ((i and f[i - 1][j]) or (j and f[i][j - 1]))) {
                    f[i][j] = 1;
                } else {
                    f[i][j] = 0;
                }
            }
        }
        return f[n - 1][m - 1];
    };

    int ans = 0;
    for (int i = 1; i * i <= a[0][0]; ++i) {
        if (a[0][0] % i) continue;
        if (check(i)) ans = std::max(ans, i);
        if (check(a[0][0] / i)) ans = std::max(ans, a[0][0] / i);
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
