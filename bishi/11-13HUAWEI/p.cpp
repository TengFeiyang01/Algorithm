#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   

    // 初始化dp数组，dp[i][j]表示前i个破损路段分成j段的最小封闭路段总长度
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 1000000000));
    dp[0][0] = 0;

    // 动态规划填表
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= std::min(i, m); ++j) {
            for (int k = i - 1; k >= j - 1; k--) {
                dp[i][j] = min(dp[i][j], dp[k][j - 1] + (a[i - 1] - a[k] + 1));
            }
        }
    }

    // 输出结果
    cout << dp[n][m] << "\n";

    return 0;
}