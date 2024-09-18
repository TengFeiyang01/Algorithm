#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
const int M = 58;

void solve() {
    int n;
    std::cin >> n;
    std::vector dp(M + 1, std::vector(n + 2, 0));
    for (int i = 1; i <= n; ++i) {
    	int x;
    	std::cin >> x;
    	dp[x][i] = i + 1;
    }
    int ans = 0;
    
    for (int i = 2; i <= M; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		if (!dp[i][j]) {
                // 以 j 为左端点 凑出 数字i的右端点 就是以dp[i-1][j]为左端点 凑出数字i-1的右端点
    			dp[i][j] = dp[i - 1][dp[i - 1][j]];
    		}
            if (dp[i][j]) {
                ans = i;
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
