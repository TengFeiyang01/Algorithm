#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][0] >> a[i][1];
    }
    std::vector<int> dp(n + 1);
    std::ranges::sort(a);
    for (int i = 0; i < n; ++i) {
    	int j = std::ranges::upper_bound(a, std::array<int, 2>{a[i][0] - a[i][1], 0}) - a.begin();
    	if (j) {
    		dp[i] = dp[j - 1] + 1;
    	} else {
    		dp[i] = 1;
    	}
    }
    std::cout << n - std::ranges::max(dp) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}