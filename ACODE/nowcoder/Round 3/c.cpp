#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    i64 n, m, a, b;
    std::cin >> n >> m >> a >> b;
    i64 ans = 0;
    for (int i = 0; i <= n and 2 * i <= m; ++i) {
    	ans = std::max(ans, i * b + a * std::min((n - i) / 2, m - 2 * i));
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
