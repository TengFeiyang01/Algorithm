#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n, k;
    std::cin >> n >> k;
    i64 ans = n * (k / (n - 1));
    if (k % (n - 1) == 0) {
        std::cout << ans - 1 << "\n";
        return;
    }

    ans += k % (n - 1);
    std::cout << ans << "\n";
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