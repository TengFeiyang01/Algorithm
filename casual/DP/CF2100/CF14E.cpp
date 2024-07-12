#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector dp(24, std::vector(5, std::vector(24, 0LL)));
    for (int i = 1; i <= 3; ++i) dp[1][i][0] = 1;
   	for (int i = 2; i <= 20; ++i) {
   		for (int y = 1; y <= 4; ++y) {
   			for (int t = 0; t <= 20; ++t) {
   				for (int h = 1; h <= 4; ++h) {
   					if (i == 2) {
   						if (y <= h) continue;
   						if (t % 2) dp[2][y][t + 1] += dp[1][h][t];
   						else dp[2][y][t] += dp[1][h][t];
   					} else {
   						if (t % 2) {
   							if (h > y) dp[i][y][t] += dp[i - 1][h][t];
   							else if (h < y) dp[i][y][t + 1] += dp[i - 1][h][t];
   						} else {
   							if (h < y) dp[i][y][t] += dp[i - 1][h][t];
   							else if (h > y) dp[i][y][t + 1] += dp[i - 1][h][t];
   						}
   					}
   				}
   			}
   		}
   	}
   	i64 ans = 0;
   	if (2 * m + 1 > n) {
   		std::cout << "0\n";
   		return;
   	}
   	for (int i = 1; i <= 4; ++i) {
   		ans += dp[n][i][2 * m - 1];
   	}
   	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
