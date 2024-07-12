#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int N = 1e5 + 31;

void solve() {
    int n;
    std::vector<i64> dp(N);
    std::array<int, 4> a, d;
    std::cin >> a[0] >> a[1] >> a[2] >> a[3] >> n;

    dp[0] = 1;
    for (auto x : a) {
    	for (int j = x; j < N; ++j) {
    		dp[j] += dp[j - x];
    	}
    }

    for (int k = 0; k < n; ++k) {
    	for (int j = 0; j < 4; ++j) {
    		std::cin >> d[j];
    	}
    	int s;
    	std::cin >> s;
    	i64 res = 0;
        // 合法方案数 减去超额的 就是正确的
    	for (int i = 1; i < 1 << 4; ++i) {
    		i64 tmp = 0, sign = -1;
    		for (int j = 0; j < 4; ++j) {
    			if (i >> j & 1) {
    				tmp += (d[j] + 1) * a[j];
    				sign = -sign;
    			}
    		}
    		if (s >= tmp) {
    			res += dp[s - tmp] * sign;
    		}
    	}
    	std::cout << dp[s] - res << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
