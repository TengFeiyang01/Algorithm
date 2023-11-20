#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    i64 n;
    std::cin >> n;
    if (n < 3) std::cout << n << "\n";
    else {
        if (n % 2) {
            std::cout << n * (n - 1) * (n - 2) << "\n";
        } else {
            if (n % 3 == 0) {
                std::cout << (n - 1) * (n - 2) * (n - 3) << "\n";
            } else {
                std::cout << n * (n - 1) * (n - 3) << "\n";
            }
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
