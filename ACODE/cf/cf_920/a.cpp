#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::vector<int> x(4), y(4);
    for (int i = 0; i < 4; ++i) {
    	std::cin >> x[i] >> y[i];
    }
    std::cout << (std::ranges::max(x) - std::ranges::min(x)) * (std::ranges::max(y) - std::ranges::min(y)) << "\n";

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
