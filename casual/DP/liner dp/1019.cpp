#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> m >> n;
    std::vector<int> dp(m + 1);

    for (int i = 0; i < n; ++i) {
    	int v, p;
    	std::cin >> v >> p;
    	for (int j = m; j >= v; --j) {
    		dp[j] = std::max(dp[j], dp[j - v] + v * p);
    	}
    }
    std::cout << dp[m] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
