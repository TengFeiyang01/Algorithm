#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
	std::vector dp(2, std::vector<i64>(2, 0));
    
    i64 res = 0, ans = 0;

    for (int i = 0; i < n; ++i) {
    	int x;
    	std::cin >> x;
    	if (x > 0) {
    		dp[(i + 1) & 1][0] = dp[i & 1][0] + 1;
    		dp[(i + 1) & 1][1] = dp[i & 1][1];
    	} else {
    		dp[(i + 1) & 1][0] = dp[i & 1][1];
    		dp[(i + 1) & 1][1] = dp[i & 1][0] + 1;
    	}
        res += dp[(i + 1) & 1][1];
        ans += dp[(i + 1) & 1][0];
    }
    std::cout << res << " " << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
