#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    i64 s = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	s += a[i];
    }
    i64 ans = 0;
    for (int i = 1; i < n; ++i) {
        s -= a[i] + a[i - 1];
        ans = std::max(ans, s + a[i] * a[i - 1]);
        s += a[i] + a[i - 1];
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}