#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 x;
    std::cin >> x;
    i64 ans = 0, l = x * x, r = (x + 1) * (x + 1);
    for (i64 i = 1; i <= x; ++i) {
    	i64 lo = l - i * i, hi = r - i * i - 1;
    	i64 lx = sqrt(lo), hx = sqrt(hi);
    	if (lx * lx < lo) lx++;
    	ans += (hx - lx + 1) * 4;
    }
    std::cout << ans << "\n";
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
