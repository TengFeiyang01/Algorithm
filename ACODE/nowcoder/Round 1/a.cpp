#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n * 3; ++i) {
        std::cout << (std::string(n, '*') + std::string(2 * n, '.') + std::string(n, '*')) << "\n";
    }
    for (int i = 1; i <= n; ++i) {
        std::cout << std::string(i, '.') + std::string(n, '*') + std::string(2 * n - 2 * i, '.');
        std::cout << std::string(n, '*') + std::string(i, '.') << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
