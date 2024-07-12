#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::array<int, 3>> op(m);
    std::vector<int> less(n);

    for (auto &[t, l, r] : op) {
        std::cin >> t >> l >> r;
        --l, --r;
        if (t) {
            for (int i = l; i < r; ++i) {
                less[i] = 1;
            } 
        }
    }

    for (auto &[t, l, r] : op) {
        bool ok = false;
        if (!t) {
            for (int i = l; i < r; ++i) {
                if (!less[i]) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                std::cout << "NO\n";
                return;
            }
        }
    }

    int ans = n;
    std::cout << "YES\n";
    std::cout << ans << " ";
    for (int i = 1; i < n; ++i) {
        if (less[i - 1]) {
            std::cout << ans << " ";
        } else {
            std::cout << --ans << " ";
        }
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
