#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    double r, x0, y0, x1, y1;
    std::cin >> r >> x0 >> y0 >> x1 >> y1;
    r *= 2;
    double d = std::sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
    

    if (d == 0) {
        std::cout << 0 << "\n";
    } else {
        std::cout << ceil(d / r) << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}