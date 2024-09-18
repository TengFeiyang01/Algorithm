#include <bits/stdc++.h>

using i64 = long long;
constexpr int mod = 998244353;


i64 qpow(i64 x, int y) {
    i64 res = 1;
    for (; y; y /= 2, x *= x, x %= mod)
        if (y & 1)
            res *= x, res %= mod;
    return res;
}

void solve() {
	int n;
	std::cin >> n;
	//dp[i][j] 还剩下 i 个瓜子和j个瓜子壳时 期望拿完的次数
    std::vector<i64> a(2 * n + 1);
	std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(n * 2 + 1));
	
    for (int i = 1; i <= 2 * n; ++i) a[i] = qpow(i, mod - 2);

    for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= 2 * n - 2; j++) {
			dp[i][j] = dp[i - 1][j + 2] * i % mod * a[i + j] % mod;
            ++dp[i][j];
            if (j)
               dp[i][j] += dp[i][j - 1] * j % mod * a[i + j] % mod;
        }
	
    std::cout << dp[n][0] % mod << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
