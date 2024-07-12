#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
const int N = 10001;

void solve() {
    int n;
    std::cin >> n;
    int g = 0;
    std::vector<int> a(n);
    std::vector<int> dp(10001);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	g = std::__gcd(g, a[i]);
    	for (int j = a[i]; j < N; ++j) {
            dp[j] |= dp[j - a[i]];
    	}
    }

    if (g != 1) {
    	std::cout << "INF\n";
    	return;
    }
    
    int ans = 0;
    for (int i = 1; i <= 10000; ++i) {
    	if (!dp[i]) {
    		ans++;
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
