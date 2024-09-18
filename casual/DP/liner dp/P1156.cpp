#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int m, n;
    std::cin >> m >> n;
    std::vector<std::array<int, 3>> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    std::ranges::sort(a);
    std::vector<int> dp(m + 1);
    // dp[j] 高度为j时 能存活的最大时间
    // 如果 dp[j] < h 等不到这个就死了
    // 如果 j + h >= m  能跳出去 输出时间
    dp[0] = 10;
    for (auto [t, v, h] : a) {
    	for (int j = m; j >= 0; --j) {
    		if (dp[j] < t) continue;
    		if (j + h >= m) {
    			std::cout << t << "\n";
    			return;
    		}
            dp[j + h] = std::max(dp[j + h], dp[j]);
            dp[j] += v;
    	}
    }
    
    std::cout << dp[0] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
