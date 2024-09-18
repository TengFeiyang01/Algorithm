#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 d;
    std::cin >> d;
    i64 ans = 1e15;
    for (i64 i = 0; i * i <= d; ++i) {
    	i64 dif = d - i * i;
        if (dif < 0) break;
    	i64 x = std::sqrt(dif);
    	ans = std::min(ans, std::abs(i * i + x * x - d));
    	++x;
    	ans = std::min(ans, std::abs(i * i + x * x - d));
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
