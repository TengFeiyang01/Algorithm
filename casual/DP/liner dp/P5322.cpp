#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int s, n, m;
    std::cin >> s >> n >> m;
    std::vector a(n, std::vector(s, 0));
    for (int i = 0; i < s; ++i) {
    	for (int j = 0; j < n; ++j) {
    		std::cin >> a[j][i];
    	}
    }
    for (int i = 0; i < n; ++i) {
    	std::ranges::sort(a[i]);
    }
    // 分组背包?
    std::vector<int> dp(m + 1);
    for (int i = 0; i < n; ++i) {
    	std::vector<int> ndp(m + 1);
    	for (int j = m; j >= 0; --j) {
    		for (int k = 0; k < s; ++k) {
    			if (j > a[i][k] * 2) {
    				dp[j] = std::max(dp[j], dp[j - 2 * a[i][k] - 1] + (k + 1) * (i + 1));
    			}
    		}
    	}
    }
    std::cout << std::ranges::max(dp);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
