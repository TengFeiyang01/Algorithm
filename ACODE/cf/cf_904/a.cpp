#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int x, k;
    std::cin >> x >> k;
    for (int i = x; i <= inf; ++i) {
        int j = i, s = 0;
        while (j) {
            s += j % 10;
            j /= 10;
        }
        if (s % k == 0) {
            std::cout << i << "\n";
            return;
        }
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