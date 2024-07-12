#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n, m;
    std::cin >> n >> m;
    std::vector<i64> x(m), y(m);
    for (i64 i = 0; i < m; ++i) {
    	std::cin >> x[i] >> y[i];
    }
    std::sort(x.begin(), x.end());
    std::sort(y.begin(), y.end());
    std::cout << std::max(x.back() - x[0] + 1, y.back() - y[0] + 1);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
