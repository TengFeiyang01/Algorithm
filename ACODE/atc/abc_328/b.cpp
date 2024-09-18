#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    int ans = 0, d;
    for (int i = 1; i <= n; ++i) {
        std::cin >> d;
        for (int j = 0; j <= d; ++j) {
            auto s = std::to_string(i) + std::to_string(j);
            if (s == std::string(s.size(), s[0])) {
                ans += 1;
            }
        }        
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
