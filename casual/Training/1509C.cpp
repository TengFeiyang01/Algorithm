#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x : a) std::cin >> x;
    std::sort(a.begin(), a.end());
	std::vector dp(n, std::vector<i64>(n));

	for (int len = 2; len <= n; ++len) {
		for (int l = 0, r = l + len - 1; r < n; ++l, ++r) {
			dp[l][r] = std::min(dp[l][r - 1], dp[l + 1][r]) + a[r] - a[l];
		}
	}
	std::cout << dp[0].back() << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
