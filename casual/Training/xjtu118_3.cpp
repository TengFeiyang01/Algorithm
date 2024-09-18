#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<i64> dp(m + 1);
    for (int i = 0; i < n; ++i) {
    	int x, y, k;
    	std::cin >> x >> y >> k;
    	if (k == -1) {
    		for (int j = x; j <= m; ++j) {
    			dp[j] = std::max(dp[j], dp[j - x] + y);
    		}
    	} else {
    		for (int j = m; j >= x; --j) {
    			dp[j] = std::max(dp[j], dp[j - x] + y);
    		}
    	}
    }

    std::cout << *std::max_element(dp.begin(), dp.end()) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
