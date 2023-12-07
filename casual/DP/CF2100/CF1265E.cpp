#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int mod = 998244353;

i64 qpow(i64 a, i64 b) {
	i64 ans = 1;
	while (b) {
		if (b & 1) {
			ans = ans * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return ans % mod;
}

// dp[i] = (dp[i - 1] + 1) * p / 100 + (dp[i - 1] + 1 + dp[i]) * (100 - p) / 100
// dp[i] * (100 + p - 100) = (dp[i - 1] + 1) * 100
// dp[i] = 100 * (dp[i - 1] + 1) / p

void solve() {
    i64 n, p;
    std::cin >> n;;
    std::vector<i64> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> p;
    	dp[i] = 100LL * (dp[i - 1] + 1LL) % mod * qpow(p, mod - 2) % mod;
    }
    std::cout << dp.back();
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
