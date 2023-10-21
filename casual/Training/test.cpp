#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 n, k;
    std::cin >> n >> k;
    i64 base = 1;
    int p = 1;
    if (n == k) {
        std::cout << n << "\n";
    } else {
        for (; k >= n / 2; p++) {
            k -= n / 2;
            n /= 2;
            base <<= 1;
        }
        std::cout << base + (1LL << p) * (k - 1) << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}