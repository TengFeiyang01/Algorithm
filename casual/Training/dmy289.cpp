#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> dp{a.begin(), a.end()};
    for (int i = 1; i < n; ++i) {
    	for (int j = 0; j < i; ++j) {
    		if (a[i] > a[j]) {
    			dp[i] = std::max(dp[i], dp[j] + a[i]);
    		}
    	}
    }
    std::cout << *std::max_element(dp.begin(), dp.end());
    // std::cout << std::ranges::max(dp) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}