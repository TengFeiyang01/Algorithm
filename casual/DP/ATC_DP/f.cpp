#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
	std::string s, t;
	std::cin >> s >> t;
	int n = s.size(), m = t.size();
	std::vector dp(n + 1, std::vector<int>(m + 1));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i] == t[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			} else {
				dp[i + 1][j + 1] = std::max({dp[i][j + 1], dp[i + 1][j]});
			}
		}
	}
	int len = dp[n][m], i = n, j = m;
	std::string ans;
	while (i and j) {
		if (s[i - 1] == t[j - 1]) {
			ans += s[i - 1];
			i--, j--;
		} else if (dp[i - 1][j] < dp[i][j - 1]) {
			j -= 1;
		} else if (dp[i][j - 1] <= dp[i - 1][j]) {
			i -= 1;
		}
	}
	std::reverse(ans.begin(), ans.end());
	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
