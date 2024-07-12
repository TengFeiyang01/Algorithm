#include <bits/stdc++.h>
 
#define pb push_back
#define eb emplace_back
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
	int n, m;
	std::cin >> n >> m;
	
	std::vector a(n + 1, std::vector<int>(m + 1));
	std::vector dp(n + 1, std::vector<int>(m + 1, -inf));
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j)
			std::cin >> a[i][j];
	for (int i = 1; i <= m; ++i) dp[0][i] = 0;

	for (int i = 1; i <= n; ++i) //第i个花
		for (int j = i; j <= m - n + i; ++j) //放置的位置
			for (int k = i - 1; k < j; ++k) //前面一个花放置的位置
				dp[i][j] = std::max(dp[i][j], dp[i - 1][k] + a[i][j]);
	int ans = 0;
	for (int i = n; i <= m; ++i) ans = std::max(ans, dp[n][i]);
	std::cout << ans << "\n";
	std::vector<int> pos;
	for (int i = n; i >= 1; --i)
		for (int j = 1; j <= m; ++j)
			if (dp[i][j] == ans) {
				pos.emplace_back(j);
				ans -= a[i][j];
				break;
			}
			
	std::reverse(pos.begin(), pos.end());
	for (int v : pos) std::cout << v << " ";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
