#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::array<int, 3>> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    std::sort(a.begin(), a.end(), [&](auto &x, auto &y){
    	for (int i = 0; i < 2; ++i) {
    		if (x[i] != y[i]) {
    			return x[i] > y[i];
    		}
    	}
    	return false;
    });

    int ans = 0;
    std::vector<int> dp(n);
    for (int i = 0; i < n; ++i) {
    	dp[i] = a[i][2];
    }

    for (int i = 0; i < n; ++i) {
    	auto x = a[i];
    	for (int j = 0; j < i; ++j) {
    		auto y = a[j];
    		if (x[0] < y[0] and x[1] < y[1] and x[2] < y[2]) {
    			dp[i] = std::max(dp[i], dp[j] + x[2]);
    		}
    	}
    }
    std::cout << *std::max_element(dp.begin(), dp.end());
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
