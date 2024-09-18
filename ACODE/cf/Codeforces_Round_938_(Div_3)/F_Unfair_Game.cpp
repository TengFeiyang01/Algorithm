#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 a, b, c, d;
    std::cin >> a >> b >> c >> d;
    bool f = false;

    if (a % 2 and b % 2 and c % 2) {
        f = true;
    }

    // 1 2 消去 3
    i64 res = std::min({a, b, c}) + d / 2;

    // 每次取两个 对xor不影响
    // 最后如果是 1 1 1 0 的话 bob赢
    res = std::max(res, a / 2 + b / 2 + c / 2 + d / 2 + f);
    
    std::cout << res << "\n";
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
