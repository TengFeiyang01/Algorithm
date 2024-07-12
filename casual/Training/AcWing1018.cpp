#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <stack>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>
#define pb push_back
#define ep emplace_back


const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e2 + 13;
int n, m, nums[N][N];

void solve() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            std::cin >> nums[i][j];

    int dp[N][N]{0};
    std::memset(dp, 0x3f, sizeof dp);
    dp[0][1] = dp[1][0] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + nums[i][j];
    std::cout << dp[n][n];

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
