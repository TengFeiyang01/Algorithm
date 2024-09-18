#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int x, y;
    std::cin >> x >> y;
    if (x > y and x - y <= 3) {
        std::cout << "Yes\n";
    } else if (y > x and y - x <= 2) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}