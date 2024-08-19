#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> dp(k + 1, inf);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
    	int a, b;
    	std::cin >> a >> b;
    	if (a > b) std::swap(a, b);
    	for (int j = k; j >= 0; --j) {
    		for (int l = 1; l <= a + b and j + l <= k; ++l) {
    			if (l <= b - a) {
    				dp[j + l] = std::min(dp[j + l], dp[j] + a * l);
    			} else {
                    // 先相等 消费(b - a) * a
                    // cost :    a         a-1         a-1         a-2  a-2
                    // 后续是 [a-1, a], [a-1, a-1], [a-2, a-1], [a-2, a-2] ...
    				int t = l - b + a;
    				int cost = (b - a) * a, cnt = (t - 1) / 2;
    				cost += a * t - (1 + cnt) * cnt;
    				if (t % 2 == 0) {
    					cost -= cnt + 1;
    				}
    				dp[j + l] = std::min(dp[j + l], dp[j] + cost);
    			}
    		}
    	}
    }
    std::cout << (dp[k] == inf ? -1 : dp[k]) << "\n";
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
