#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n, m, x, y;
    std::cin >> n >> m >> x >> y;
    n -= m;
    if (y < x) {
        std::cout << "No\n";
        return;
    }
    y -= x;
    if (y > n) {
        std::cout << "No\n"; 
    } else {
        std::cout << "Yes\n";
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
