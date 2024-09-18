#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int N;
    std::cin >> N;
    std::vector<i64> dp{0};
    int s = 0;
    //n个物品 问选购价值为s+1/2的最小代价
    for (int i = 0; i < N; ++i) {
        int X, Y, Z;
        std::cin >> X >> Y >> Z;
        
        int cost = std::max(0, (X + Y + 1) / 2 - X);

    	s += Z;
    	dp.resize(s + 1, 1e18);
    	for (int i = s; i >= Z; --i) {
    		dp[i] = std::min(dp[i], dp[i - Z] + cost);
    	}
    }
    
    i64 ans = *std::min_element(dp.begin() + (s + 1) / 2, dp.end());
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}