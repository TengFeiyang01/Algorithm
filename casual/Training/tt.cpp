#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1), dp(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    }
    i64 s = 1;
    dp[0] = 1;
    std::vector<int> st;
    for (int i = 1; i <= n; ++i) {
    	if (dp[i] + 1 == a[i]) {
    		st.push_back(i);
    		// 背包刷 dp
    		auto g = dp;
    		for (int j = n; j >= i; --j) {
    			g[j] = g[j] + dp[j - i];
    		}
    		dp = g;
    	} else {
    		if (dp[i] == a[i]) {
    			continue;
    		} else {
    			// -1
    		}
    	}
    }
}
// dp[i+1] = \sum_t dp[i+1-s_t]  ，s_t属于确认的银币集合

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
