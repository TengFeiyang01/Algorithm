#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<i64, 3>> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][0];
    }
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][1];
        a[i][2] = a[i][0] + a[i][1];
    }
    // a - 1 
    // -(b - 1)   差值为 a+b
    std::ranges::sort(a, [&](auto &x, auto &y){
        return x[2] > y[2];
    });

    i64 ans = 0;
    int l = 0, r = n - 1;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            ans += a[i][0] - 1;
        } else {
            ans -= a[i][1] - 1;
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
