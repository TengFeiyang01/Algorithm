#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    const int N = 800000, M = 400000;
    std::vector dp(N + 1, -inf);
    // 由于存在负数 可以将状态设计为 dp[i][j] 前i头牛 情商为j 智商为dp[i][j] 那么答案为max(dp[n][j] + j) j >=0  
    // 由于 v 可能为负数 转移的时候根据正负 正序/倒序 dp
    dp[M] = 0;
    for (int i = 0; i < n; ++i) {
    	int v, w;
    	std::cin >> v >> w;
    	if (v >= 0) {
    		for (int j = N; j >= v; --j) {
    			dp[j] = std::max(dp[j], dp[j - v] + w);
    		}
    	} else {
    		for (int j = 0; j <= N + v; ++j) {
    			dp[j] = std::max(dp[j], dp[j - v] + w);
    		}
    	}
    }
    int ans = 0;
    for (int i = M; i <= N; ++i) {
    	if (dp[i] > 0) {
    		ans = std::max(ans, dp[i] + i - M);
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
