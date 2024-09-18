#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int N, W;
    std::cin >> N >> W;
    std::vector<int> w(N), v(N);
    for (int i = 0; i < N; ++i) {
    	std::cin >> w[i] >> v[i];
    }
    std::vector<i64> dp(W + 1);
    i64 ans = 0;
    
    for (int i = 0; i < N; ++i) {
    	for (int j = W; j >= w[i]; --j) {
    		dp[j] = std::max(dp[j], dp[j - w[i]] + v[i]);
    	}
    }
    for (int i = 0; i <= W; ++i) ans = std::max(ans, dp[i]);
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
