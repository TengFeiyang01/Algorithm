#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

const int mod = 1000000007;

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<i64> dp(k + 1), pre(k + 1);
	dp[0] = 1;
	for (int i = 1; i < n - 1; ++i) {
    	for (int j = 1; j < k + 1; ++j) {
    		dp[j] = j < i ? pre[j] : (pre[j] - pre[j - i]);
    	}
    	for (int j = 0; j < k + 1; ++j) {
    		pre[j] = (j == 0 ? 0 : pre[j - 1]) + dp[j] % mod;
    	}
    }
    i64 ans = 0;
    for (int i = 1; i < k + 1; ++i) {
    	dp[i] = (dp[i - 1] + dp[i]) % mod;
    }

    for (int i = 0; i < n; ++i) {
    	for (int j = i + 1; j < n; ++j) {
    		int now = k - i - j + 1;
    		if (now >= 0) {
    			ans += dp[now];
    			ans %= mod;
    		}
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
