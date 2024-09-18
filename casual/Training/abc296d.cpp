#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    i64 n, m, ans = 1E18;
    std::cin >> n >> m;
    for (i64 a = 1; a <= n; ++a) {
    	i64 b = (m + a - 1) / a;
    	if (b < a) break;
    	if (b <= n) {
    		ans = std::min(ans, a * b);
    	}
    }
    if (ans == 1E18) ans = -1;
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
