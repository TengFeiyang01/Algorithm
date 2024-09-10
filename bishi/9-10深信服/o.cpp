#include <bits/stdc++.h>

int main() {
    int n = 100;  // 假设有n个数
    int m = 100;  // 假设异或和最大为m
    std::cin >> n >> m;
    std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(m + 1, std::vector<int>(m + 1, 0)));
    int ans = 0;
    // 假设初始化 dp[0][...][...] 的值
    for (int i = 0; i <= m; ++i) {
    	dp[0][i][i] = 1;
    }
    
    for (int i = 1; i < n; ++i) {
        std::vector<std::vector<int>> prefix_sum(m + 1, std::vector<int>(m + 1, 0));
        
        // 构建前缀和数组
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= m; ++k) {
                prefix_sum[j][k] = dp[i-1][j][k];
                if (k > 0) {
                    prefix_sum[j][k] += prefix_sum[j][k-1];
                }
            }
        }
        
        // 使用前缀和计算 dp[i][j][k]
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= m; ++k) {
                dp[i][j][k] = prefix_sum[j^k][k];
            	if (i == n - 1 and j == m) {
            		ans == dp[i][j][k];
            	}
            }
        }
    }
    std::cout << ans;

    return 0;
}
