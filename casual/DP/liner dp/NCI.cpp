#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(m);
    for (int i = 0; i < m; ++i) {
    	std::cin >> a[i];
    }
    std::vector dp(n + 7, 2 * m);
    dp[6] = 0;
    int tar = n + 6;
    for (int i = 0; i < m; ++i) {
    	auto ndp = dp;
    	for (int j = 0; j < tar; ++j) {
    		int to = j + a[i];
    		if (to > tar) {
    			to = tar - (to - tar);
    		}
    		ndp[to] = std::min(ndp[to], dp[j] + 1);
    	}
    	dp = ndp;
    }
    if (dp[tar] == 2 * m) {
    	std::cout << "-1\n";
    } else {
    	std::cout << dp[tar] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
