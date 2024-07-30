#include <bits/stdc++.h>
using i64 = long long;


void solve() { 
    int n;
    std::cin >> n;
    std::vector<std::array<int, 2>> a(n);

    i64 X, Y;
    std::cin >> X >> Y;
    for (int j = 0; j < 2; ++j) {
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i][j];
            a[i][j] = -a[i][j];
        }
    }


    std::ranges::sort(a);

    i64 ans = n;
    for (i64 i = 0, cur = 0; i < n; ++i) {
        cur -= a[i][0];
        if (cur > X) {
            ans = std::min(ans, i + 1);
            break;
        }
    }
    for (auto &x : a) {
        std::swap(x[0], x[1]);
    }
    
    std::ranges::sort(a);
    for (i64 i = 0, cur = 0; i < n; ++i) {
        cur -= a[i][0];
        if (cur > Y) {
            ans = std::min(ans, i + 1);
            break;
        }
    }
    std::cout << ans << "\n";

}

int main() {
    std::ios::sync_with_stdio(0),std::cin.tie(0);
    
    solve();

    return 0;
}