#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n + 1);
    std::vector dp(n + 1, std::vector<i64>(n + 1));
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    	a[i] += a[i - 1];
    }
    for (int len = 2; len <= n; ++len) {
    	for (int l = 1, r = l + len - 1; r <= n; ++l, ++r) {
    		i64 res = 1e15;
    		for (int k = l; k < r; ++k) {
    			res = std::min(res, dp[l][k] + dp[k + 1][r] + a[r] - a[l - 1]);
    		}
    		dp[l][r] = res;
    	}
    }
    std::cout << dp[1][n] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}