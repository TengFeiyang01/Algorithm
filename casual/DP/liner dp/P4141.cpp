#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector dp(m + 1, 0LL);
    dp[0] = 1;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	for (int j = m; j >= a[i]; --j) {
    		dp[j] += dp[j - a[i]];
            dp[j] %= 10;
    	}
    }
    std::vector<int> g(m + 1);
    for (int x : a) {
        g[0] = 1;
        for (int j = 1; j <= m; ++j) {
            if (x > j) {
                g[j] = dp[j] % 10;
            } else {
                g[j] = (dp[j] - g[j - x] + 10) % 10;
            }
            std::cout << g[j];
        }
        std::cout << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
