#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int tot = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	tot += a[i];
    }

    std::vector<int> dp(tot + 1);
    
    for (int i = 1; i <= n; ++i) {
        std::vector<int> ndp(tot + 1);
        int x = a[i - 1];
        for (int j = tot; j >= 0; --j) {
            if (j == x) ndp[j] = 1;
            else if (dp[j]) ndp[j] = 1;
            else if (j + x <= tot and dp[j + x]) ndp[j] = 1;
            else if (dp[abs(j - x)]) ndp[j] = 1;
        }
        dp = ndp;
    }

    int ans = 0;
    for (int i = 1; i <= tot; ++i) {
    	if (dp[i]) {
    		ans++;
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
