#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 a, b;
    std::cin >> a >> b;
    i64 ans = a * b / std::__gcd(a, b);
    if (ans == b) {
        std::cout << b * b / a << "\n";
        return ;
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
