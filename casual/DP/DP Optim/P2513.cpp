#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
const int MOD = 10000;

// 前缀和优化DP
// DP[i][j] 表示前i个数的全排列有j个逆序对的个数
void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector dp(n + 1, std::vector<i64>(k + 1));
    dp[1][0] = 1;
    for (int i = 2; i <= n; ++i) {
    	i64 sum = 0;
    	for (int j = 0; j <= k; ++j) {
    		sum = (sum + dp[i - 1][j]) % MOD;
    		dp[i][j] = sum;
    		if (j >= i - 1) {
    			sum -= dp[i - 1][j - i + 1];
    			sum = (sum + MOD) % MOD;
    		}
    	}
    }
    std::cout << dp[n][k];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
