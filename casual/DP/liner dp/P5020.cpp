#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::ranges::sort(a);
    int m = a.back(), ans = 0;
    std::vector<bool> dp(m + 1);
    dp[0] = true;
    for (auto x : a) {
    	if (!dp[x]) {
    		ans++;
    	}
    	for (int j = x; j <= m; ++j) {
    		dp[j] = dp[j] or dp[j - x];
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
