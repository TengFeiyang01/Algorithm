#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
#if 1
void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::string s, t;
    std::cin >> s >> t;
    // dp[i][j][k][2] s的前i个取出j个 拼成t的前k个的方案数

    // 考虑转移  当s[i]==t[j]: dp[i][j][p][1] = dp[i - 1][j - 1][p - 1][0/1] + dp[i - 1][j - 1][p][1]//和前面的成一段 那么前一个必选
    //                       dp[i][j][p][0] = dp[i - 1][j][p][0/1]  当前不选 只能是之前凑出长度为j的p段了
    //          当s[i]!=t[j]: dp[i][j][p][0] = dp[i - 1][j][p][0/1] 
    //                        dp[i][j][p][1] = 0 

    const int MOD = 1000000007;
    std::vector dp(m + 1, std::vector(k + 1, std::vector<i64>(2)));
    auto ndp = dp;
    dp[0][0][0] = 1;
    ndp[0][0][0] = 1;
    for (int i = 1; i <= n; ++i) { 
    	for (int j = 1; j <= m; ++j) {
    		for (int p = 1; p <= k; ++p) {
    			if (s[i - 1] == t[j - 1]) {
                    // 考虑到当 s[i] == t[j]时： dp[i][j][k][0/1] = dp[i-1][j][k][0/1] + sum(dp[i-t][j-t][k-1]) 当s[i-t]==t[j-t]时
    				ndp[j][p][1] = (dp[j - 1][p][1] + dp[j - 1][p - 1][0] + dp[j - 1][p - 1][1]) % MOD;
    				ndp[j][p][0] = (dp[j][p][0] + dp[j][p][1]) % MOD;
    			} else {
    				ndp[j][p][0] = (dp[j][p][0] + dp[j][p][1]) % MOD;
    				ndp[j][p][1] = 0;
    			}
    		}
    	}
    	dp = ndp;
    }
    std::cout << (dp[m][k][0] + dp[m][k][1]) % MOD;
}
#endif

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
