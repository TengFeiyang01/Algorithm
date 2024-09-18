#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> dp(2);
    
    for (int i = 0; i < n; ++i) {
    	int x, y;
        std::cin >> x >> y;
        if (x == 0) {
            dp[0] = std::max(dp[0], std::max(dp[0], dp[1]) + y);
        } else {
            dp[1] = std::max(dp[1], dp[0] + y);
        }
    }

    std::cout << std::max(dp[0], dp[1]);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
