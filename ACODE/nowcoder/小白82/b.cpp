#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    double x, y;
    std::cin >> n >> x >> y;
    x /= 100;
    std::vector<double> a(n);
    int tot = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	tot += a[i];
    }
    std::sort(a.begin(), a.end());
    if (n == 1) {
    	std::cout << std::min(x * a[0], std::max(0.0, a[0] - y));
    } else {
        std::cout << std::fixed;
    	std::cout << tot - a[n - 1] - a[n - 2] + std::min(a[n - 1] * x + std::max(a[n - 2] - y, 0.0), a[n - 2] * x + std::max(a[n - 1] - y, 0.0)) << "\n";
    }
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
