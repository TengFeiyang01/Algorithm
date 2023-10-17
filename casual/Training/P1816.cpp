#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    int k = std::log2(n);
    std::vector dp(n, std::vector(k + 1, inf));
    for (int i = 0; i < n; ++i) {
        std::cin >> dp[i][0];
    } 
    for (int j = 1; j <= k; ++j) {
    	for (int i = 0; i + (1 << j) < n; ++i) {
            dp[i][j] = std::min(dp[i][j - 1], dp[i + (1 << j - 1)][j - 1]);
    	}
    }
    
    while (q--) {
    	int l, r;
    	std::cin >> l >> r;
        --r, --l;
    	int x = std::log2(r - l + 1);
    	std::cout << std::min(dp[l][x], dp[r - (1 << x) + 1][x]) << " ";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}