#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
const int mod = 1e9+7;

void solve() {
    int n;
    std::cin >> n;
    //0表示空 1
    std::vector<i64> dp(4);
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
    	dp[i % 4] = (dp[(i + 3) % 4] * 2 + dp[(i + 1) % 4]) % mod;
    }
    std::cout << dp[n % 4];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
