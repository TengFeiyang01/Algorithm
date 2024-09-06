#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 a, b, c , d;
    std::cin >> a >> b >> c >> d;
    int n;
    std::cin >> n;
    i64 ans = 1e18, tot = 0;
    std::vector<std::array<i64, 2>> p(n);

    for (int i = 0; i < n ; ++i) {
    	std::cin >> p[i][0] >> p[i][1];
    	tot += 2LL * (abs(p[i][0] - c) + abs(p[i][1] - d));
    }
    for (int i = 0; i < n; ++i) {
    	ans = std::min(ans, tot - (abs(p[i][0] - c) + abs(p[i][1] - d)) + (abs(p[i][0] - a) + abs(p[i][1] - b)));
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
