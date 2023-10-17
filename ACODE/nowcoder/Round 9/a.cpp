#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    int s = 1;
    for (int i = 0; i < n; ++i) {
        int x, m;
        std::cin >> m >> x;
        int ans = 0;
        if (x % m == 0) {
            ans = m;
        } else {
            ans = x % m;
        }
        std::cout << ans << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}