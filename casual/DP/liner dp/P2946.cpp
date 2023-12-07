#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int mod = 100000000;

void solve() {
    int n, f;
    std::cin >> n >> f;
    std::vector<int> dp(f);
    dp[0] = 1;

    for (int i = 0; i < n; ++i) {
    	std::vector<int> ndp(f);
        int x;
        std::cin >> x;
    	for (int j = 0; j < f; ++j) {
    		ndp[j] = dp[j] + dp[((j - x) % f + f) % f];
    		ndp[j] %= mod;
    	}
    	dp.swap(ndp);
    }
    std::cout << dp[0] - 1 << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
