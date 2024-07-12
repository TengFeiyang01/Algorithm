#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n;
    std::cin >> n;
    i64 ans = 1;
    for (i64 i = 2; i * i <= n; ++i) {
        if (n % i == 0 and (n / i) * (n / i) > n) {
            ans = n / i;
        }
    }        
    if (ans == 1) {
        ans = n;
    }
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
