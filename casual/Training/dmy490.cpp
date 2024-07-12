#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int p, n;
    std::cin >> p >> n;
    std::vector<int> inv(n + 1);
    inv[1] = 1;
    int ans = 1;
    for (int i = 2; i <= n; ++i) {
        // 模p意义下 -p/i 和 p-p/i等价
    	inv[i] = (i64)(p - p / i) * inv[p % i] % p;
    	ans ^= inv[i];
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
