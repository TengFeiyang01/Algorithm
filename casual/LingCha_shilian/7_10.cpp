#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector dp(2, std::vector<int>(3, inf));
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    dp[0][1] = 0;
    dp[0][0] = 0;
    dp[0][2] = 0;
    for (int i = 0; i < n; ++i) {
    	if (a[i] == 2 or a[i] == 3) {
    		dp[(i + 1) & 1][2] = std::min(dp[i & 1][0], dp[i & 1][1]);
    	} else {
    		dp[(i + 1) & 1][2] = inf;
    	}
    	if (a[i] == 1 or a[i] == 3) {
    		dp[(i + 1) & 1][1] = std::min(dp[i & 1][0], dp[i & 1][2]);
    	} else {
    		dp[(i + 1) & 1][1] = inf;
    	}
    	dp[(i + 1) & 1][0] = std::min({dp[i & 1][0], dp[i & 1][1], dp[i & 1][2]}) + 1;
    }
    std::cout << std::min({dp[n & 1][0], dp[n & 1][1], dp[n & 1][2]});
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
