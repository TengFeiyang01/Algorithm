#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> a(n);
    std::vector<int> dp(1 << m, inf);
    for (int i = 0; i < n; ++i) {
    	int now = 0, x;
    	for (int j = 0; j < k; ++j) {
    		std::cin >> x;
    		now |= (1 << (x - 1));
    	}
    	a[i] = now;
        dp[now] = 1;
    }
    for (int i = 1; i < 1 << m; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i | a[j]] = std::min(dp[i | a[j]], dp[i] + 1);
        }
    }
    if (dp[(1 << m) - 1] == inf) {
        std::cout << "-1\n";
        return;
    }
    std::cout << dp.back();
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}