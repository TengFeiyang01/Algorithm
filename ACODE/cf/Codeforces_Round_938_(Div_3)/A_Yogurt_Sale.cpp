#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;
    std::cout << a * (n & 1) + std::min(a * (n - (n & 1)), b * (n / 2)) << "\n";
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
