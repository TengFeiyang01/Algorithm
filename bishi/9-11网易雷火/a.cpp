#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    if (m == n) {
        std::cout << m << "\n";
        return;
    }
    m++, n++;
    int g = std::__gcd(n, m);
    int ans = (m / g + n / g - 1) * g;
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
