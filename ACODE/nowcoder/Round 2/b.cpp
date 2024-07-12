#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::string s;
	std::cin >> s;
	i64	ans = 0;
	std::vector<i64> dp(n);
	for (int i = 1; i < n; ++i) {
		if (s[i] != s[i - 1]) {
			dp[i] = std::max((i < 2 ? 0LL : dp[i - 2]) + a[i] + a[i - 1], dp[i - 1]);
		} else {
			dp[i] = dp[i - 1];
		}
		ans	 = std::max(ans, dp[i]);
	}	
	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
