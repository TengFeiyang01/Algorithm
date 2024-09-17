#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 3>> a(n);
    for (int i = 0; i < n; ++i) {
    	for (int k = 0; k < 3; ++k) {
    		std::cin >> a[i][k];
    	}
    	std::swap(a[i][0], a[i][1]);
    	a[i][0]++;
    }
    std::sort(a.begin(), a.end());
    std::vector<int> dp(n + 1);
    for (int i = 0; i < n; ++i) {
    	int k = std::upper_bound(a.begin(), a.begin() + i, std::array<int, 3>{a[i][1], INT_MAX}) - a.begin();
    	dp[i + 1] = std::max(dp[i], dp[k] + a[i][2]);
    }
    std::cout << dp[n] << "\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
