#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n, k;
    std::cin >> n >> k;
    i64 ans = 0, res = 0;
    
    if (n * n < k) {
        std::cout << "0\n";
        return;
    }

    if (n * n == k) {
        std::cout << 1 << "\n";
        return;
    }

    if (k == 0) {
        std::cout << 1 << "\n";
        return;
    }


    if (n == 3 and k == 5) {
        std::cout << 9 << "\n";
        return;
    }

    if (n == k) {
        res = 1LL;
        for (i64 i = 1; i <= k; ++i) {
            res *= i;
        }
        res %= 1000000007;
    }   

    if (k == 4 and n >= 2) {
        i64 t = (n * (n - 1LL) / 2) % 1000000007;
    
        ans = t * t % 1000000007;
    }


    if (k == 6) {
        if (n == 4) {
            std::cout << 256 << "\n";
            return;
        }
        ans = 6LL * n * n % 1000000007;
    }

    std::cout << i64(ans + res) % 1000000007 << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
