#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, t;
    std::cin >> n >> m >> t;
    std::vector dp(m + 1, std::vector(t + 1, 0));
    for (int i = 0; i < n; ++i) {
    	int v, w;
    	std::cin >> v >> w;
    	for (int j = m; j >= v; --j) {
    		for (int k = t; k >= w; --k) {
    			dp[j][k] = std::max(dp[j][k], dp[j - v][k - w] + 1);
    		}
    	}
    }
    std::cout << dp[m][t];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
