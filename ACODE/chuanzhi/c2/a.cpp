#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int ans, n, x;
    std::cin >> n >> x;
    for (int i = 0, pre, y; i < n; ++i) {
    	std::cin >> y;
        if (i) {
            ans += (pre < x and y >= x);
        }
        pre = y;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
