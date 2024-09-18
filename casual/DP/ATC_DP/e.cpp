#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;

void solve() {
    int N, W;
    std::cin >> N >> W;
    constexpr int mx = 100010;
    std::vector<i64> dp(mx + 1, inf);
    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
    	int w, v;
    	std::cin >> w >> v;
    	for (int j = mx; j >= v; --j) {
    		dp[j] = std::min(dp[j], dp[j - v] + w);
    	}
    }
    int ans = 0;
    for (int i = 0; i <= mx; ++i) {
    	if (dp[i] <= W) {
    		ans = i;
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
