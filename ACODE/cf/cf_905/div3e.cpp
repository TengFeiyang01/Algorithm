#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n), dp(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    i64 ans = 0;
    for (int i = 1; i < n; ++i) {
        i64 v = a[i];
        int cnt = 0;
        dp[i] = dp[i - 1];
        if (v < a[i - 1]) {
        	while (v < a[i - 1]) {
        		v *= 2;
                cnt++;
        	} 
            dp[i] += cnt;
        } else {
            i64 w = a[i - 1];
            while (w * 2 <= v) {
                w *= 2;
                dp[i]--;
            }
            dp[i] = std::max(dp[i], 0LL);
        }
        ans += dp[i];
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