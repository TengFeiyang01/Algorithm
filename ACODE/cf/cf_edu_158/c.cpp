#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    int x = std::ranges::min(a), y = std::ranges::max(a);
    std::vector<int> res;

    while (x != y) {
        if (x % 2 == y % 2) {
            res.push_back(0);
        } else if (y % 2 == 0) {
            res.push_back(1);
            ++x;
        } else {
            res.push_back(0);
        }
        x >>= 1;
        y >>= 1;
    }
    std::cout << res.size() << "\n";
    if (res.size() > n) return;
    for (int i = 0; i < res.size(); ++i) {
        std::cout << res[i] << " \n"[i == res.size() - 1];
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
