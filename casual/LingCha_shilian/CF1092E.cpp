#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, c;
    std::cin >> n >> c;
    std::vector<int> a(n + 1), sum(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    	sum[i] = sum[i - 1] + (a[i] == c);
    }
    // sum[1, l-1] + sum[l, r][other] + sum[r+1, n]
    std::map<int, int> dp;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
    	dp[a[i]] = std::max(dp[a[i]] + 1, sum[i - 1] + 1);
    	ans = std::max(ans, dp[a[i]] + sum[n] - sum[i]);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}