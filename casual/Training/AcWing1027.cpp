#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>

const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 13;
int n, m, nums[N][N]{0};

void solve() {
    std::cin >> n;
    while (1) {
        int x, y, w;
        std::cin >> x >> y >> w;
        if (x == y && y == w && x == 0) break;
        nums[x][y] = w;
    }
    int dp[N][N]{0};
    dp[1][1] = nums[1][1];
    for (int k = 3; k <= n * 2; ++k)
        for (int x1 = std::min(k, n); x1 >= std::max(k - n, 1); --x1)
            for (int x2 = std::min(k, n); x2 >= x1; --x2) {
                int y1 = k - x1, y2 = k - x2;
                int res = dp[x1][x2];
                res = std::max(dp[x1 - 1][x2], res);
                res = std::max(dp[x1 - 1][x2 - 1], res);
                res = std::max(dp[x1][x2 - 1], res);
                res += nums[x1][y1];
                if (x1 != x2) res += nums[x2][y2];
                dp[x1][x2] = res;
            }
    std::cout << dp[n][n] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
