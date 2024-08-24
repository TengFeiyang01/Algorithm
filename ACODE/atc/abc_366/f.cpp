#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::array<int, 2>> f(n);
    for (auto &[a, b] : f) {
    	std::cin >> a >> b;
    }
    std::ranges::sort(f, [&](auto x, auto y){
    	auto [a1, b1] = x;
    	auto [a2, b2] = y;
    	return (a2 - 1) * b1 > (a1 - 1) * b2;
    });
    std::vector<i64> dp(k + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
    	auto& [a, b] = f[i];
    	auto ndp = dp;
    	for (int j = 1; j <= k; ++j) {
    		ndp[j] = std::max(ndp[j], a * dp[j - 1] + b);
    	}
    	dp.swap(ndp);
    }
    std::cout << dp.back() << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
