#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> f(50001, inf);
    f[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        auto g = f;
        f = std::vector<int>(50001, inf);
        std::cin >> x;
        for (int j = 0; j <= 5000; ++j) {
            if (j >= x) {
                f[j] = std::min(f[j], g[j - x] + x);
            }
            if (j + 100 <= 5000) {
                f[j + x] = std::min(f[j + x], g[j + 100]);
            }
        }
    }

    std::cout << *std::min_element(f.begin(), f.end()) << "\n";
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
