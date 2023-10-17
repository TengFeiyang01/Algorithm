#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = unsigned long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;


void solve() {
    i64 ans = 0;
    for (int i = 0; i < 64; ++i) {
    	i64 x;
    	std::cin >> x;
        ans += x << i;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
