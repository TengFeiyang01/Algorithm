#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n, k;
    std::cin >> n >> k;
    if (n % k) {
    	std::cout << "-1\n";
    } else {
        n /= k;
        if (n & 1) {
            i64 y = n - 1;
            bool f = 0;
            i64 ans = 0;

            for (i64 tmp = y / 2; tmp > 1; --tmp) {
                i64 oth = y - tmp;
                if (std::__gcd(tmp, oth) == 1) {
                    ans = tmp;
                    f = 1;
                    break;
                }
            }
            if (!f) {
                std::cout << -1 << "\n";
            } else {
                std::cout << k << " " << ans * k << " " << (y - ans) * k << "\n";
            }
        } else {
            i64 y = n - 3;
            if (y > 2) {
                std::cout << k << " " << 2 * k << " " << y * k << "\n"; 
            } else {
                std::cout << -1 << "\n";
            }
        }
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
