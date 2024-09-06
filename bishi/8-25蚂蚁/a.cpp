#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x, y, k;
    cin >> n >> x >> y >> k;
    
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    // dp[time][pos] 表示第 time 秒时位于 pos 的最大金币收益
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));

    // 初始化：第 0 秒，小廖在中路
    dp[0][1] = 0;


    for (int i = 1; i <= n; ++i) {
        // 上路
        dp[i][0] = dp[i-1][0] + a[i-1]; // 从上路继续待在上路
        if (i >= x) {
            dp[i][0] = max(dp[i][0], dp[i-x][1] + a[i-1]); // 从中路转移到上路
        }
        if (i >= x + y) {
            dp[i][0] = max(dp[i][0], dp[i-(x+y)][2] + a[i-1]); // 从下路通过中路转移到上路
        }

        // 中路
        dp[i][1] = dp[i-1][1] + b[i-1]; // 从中路继续待在中路
        if (i >= x) {
            dp[i][1] = max(dp[i][1], dp[i-x][0] + b[i-1]); // 从上路转移到中路
        }
        if (i >= y) {
            dp[i][1] = max(dp[i][1], dp[i-y][2] + b[i-1]); // 从下路转移到中路
        }

        // 下路
        dp[i][2] = dp[i-1][2] + c[i-1]; // 从下路继续待在下路
        if (i >= y) {
            dp[i][2] = max(dp[i][2], dp[i-y][1] + c[i-1]); // 从中路转移到下路
        }
        if (i >= x + y) {
            dp[i][2] = max(dp[i][2], dp[i-(x+y)][0] + c[i-1]); // 从上路通过中路转移到下路
        }

        // 计算防御塔的辅助击杀收益
        if (abs(x) <= k) dp[i][1] = max(dp[i][1], dp[i][0] + b[i-1] / 2); // 上路防御塔影响中路
        if (abs(y) <= k) dp[i][1] = max(dp[i][1], dp[i][2] + b[i-1] / 2); // 下路防御塔影响中路
        if (abs(x) <= k) dp[i][0] = max(dp[i][0], dp[i][1] + a[i-1] / 2); // 中路防御塔影响上路
        if (abs(y) <= k) dp[i][2] = max(dp[i][2], dp[i][1] + c[i-1] / 2); // 中路防御塔影响下路
    }
    // 找出最后一秒最大收益
    int result = max({dp[n][0], dp[n][1], dp[n][2]});

    cout << result << endl;

    return 0;
}
