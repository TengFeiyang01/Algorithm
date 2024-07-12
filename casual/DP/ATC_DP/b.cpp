#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> dp(n, inf);
    dp[0] = 0;
    dp[1] = abs(a[1] - a[0]);
    for (int i = 2; i < n; ++i) {
    	for (int j = i - 1; j >= 0 and i - j <= k; --j) {
    		dp[i] = std::min(dp[i], dp[j] + abs(a[j] - a[i]));
    	}
    }
    std::cout << dp.back();
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
