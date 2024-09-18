#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int mod = 1e9+7;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector dp(n + 1, std::vector<i64>(m + 1));
    dp[0][2] = 1;
    for (int i = 1; i < n + m; ++i) {
	    std::vector ndp(n + 1, std::vector<i64>(m + 1));
	    for (int j = 0; j <= n; ++j) {
	    	for (int k = 0; k <= m; ++k) {
	    		if (k % 2 == 0 and j) ndp[j][k] = (dp[j - 1][k / 2] + ndp[j][k]) % mod;
	    		if (k + 1 <= m) ndp[j][k] = (ndp[j][k] + dp[j][k + 1]) % mod;
	    	}
	    }
	    dp.swap(ndp);
    }
    std::cout << dp[n][1] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
