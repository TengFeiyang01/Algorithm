#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s;
    std::cin >> s;
    
    int n = s.size();
    
    int c1 = std::count(s.begin(), s.end(), '1'), c0 = n - c1;
    
    //11已知 00已知  10==01 need是目标01和11的个数
    int need = (n * (n - 1) / 2 - c0 * (c0 - 1) / 2 + c1 * (c1 - 1) / 2) / 2;
    
    //一维1的数量，二维01和11的个数，内容是最小答案
    std::vector dp(c1 + 1, std::vector<int>(need + 1, inf));
    dp[0][0] = 0;
    
    //前i个位置放j个1
    for (int i = 0; i < n; i++) {
        for (int j = c1 - 1; j >= 0; j--) {  //01新增是 (i - j) 11新增是j 总和 i+j
            for (int k = 0; k + i <= need; k++) {  //第i位放1,01和11增量就是i
                dp[j + 1][k + i] = std::min(dp[j + 1][k + i], dp[j][k] + (s[i] == '0'));
            }
        }
    }
    std::cout << dp[c1][need] << "\n";
    
    return 0;
}
