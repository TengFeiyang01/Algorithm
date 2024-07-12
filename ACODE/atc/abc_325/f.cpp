#include <bits/stdc++.h>
 
using i64 = long long;
constexpr i64 inf = 1e15;

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> D(N);
    for (int i = 0; i < N; ++i) {
    	std::cin >> D[i];
    }

    // dp[i][j] 处理到前 i 个 使用了 j 个1号的情况下 需要的最少的2号的个数

    int l1, c1, k1, l2, c2, k2;
    std::cin >> l1 >> c1 >> k1 >> l2 >> c2 >> k2;
    std::vector dp(N + 1, std::vector<i64>(k1 + 1, inf));
    dp[0][0] = 0;
    for (int i = 0; i < N; ++i) {
    	for (int j = 0; j <= k1; ++j) {
    		for (int nj = j; nj <= k1; ++nj) {
    			dp[i + 1][nj] = std::min(dp[i + 1][nj], dp[i][j] + std::max(D[i] - (nj - j) * l1 + l2 - 1, 0) / l2);
    		}
    	}
    }
   		
   	i64 ans = inf;
   	for (int j = 0; j <= k1; ++j) {
   		if (dp[N][j] <= k2) {
   			ans = std::min(ans, 1LL * j * c1 + dp[N][j] * c2);
   		}
   	}
    if (ans == inf) ans = -1;
   	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}