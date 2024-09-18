#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int x;
    std::vector<int> f, g;

    while (std::cin >> x) {
        if (f.empty() or f.back() <= x) {
            f.push_back(x);
        } else {
            auto it = std::lower_bound(f.begin(), f.end(), x);
            *it = x;
        }
        if (g.empty() or g.back() >= x) {
            g.push_back(x);
        } else {
            auto it = std::lower_bound(g.begin(), g.end(), x, std::greater<int>());
            *it = x;
        }
    }
    std::cout << g.size() << "\n" << f.size() << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
