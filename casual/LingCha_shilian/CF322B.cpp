#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int a, b, c, ans;
    std::cin >> a >> b >> c;
    ans = std::min({a, b, c});
    a -= ans;
    b -= ans;
    c -= ans;
    if (a % 3 + b % 3 + c % 3 == 4 and ans) ans++;
    ans += a / 3 + b / 3 + c / 3;
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
