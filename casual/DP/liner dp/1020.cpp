#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), dp;
    
    int s = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	s += a[i];
    }
    int t = s >> 1;

    dp.resize(t + 1);
    for (int x : a) {
    	for (int j = t; j >= x; --j) {
    		dp[j] = std::max(dp[j], dp[j - x] + x);
    	}
    }
    std::cout << dp[t] << " " << s - dp[t] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
