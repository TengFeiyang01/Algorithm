#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
#define YES "YES\n"
#define Yes "Yes\n"
#define NO "NO\n"
#define No "No\n"
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e2 + 13;

void solve() {
    int w, h;
    std::cin >> w >> h;
    std::vector a(N, std::vector<int>(N));
    std::vector dp(N, std::vector<int>(N, -inf));
    int t, p, v, c, n = 0;
    h--;

    while (std::cin >> t >> p >> v >> c) {
    	if (h % v == 0) {
    		t = t + h / v;
    		a[t][p] += c;
    		n = std::max(n, t);
    	}
    }

    for (int i = 1; i <= w; ++i) dp[0][i] = -inf;
    dp[0][(w + 1) / 2] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= w; ++j) 
			for (int k = -2; k <= 2; ++k)
				if (1 <= j + k and j + k <= w) 
					dp[i][j] = std::max(dp[i][j], dp[i - 1][j + k] + a[i][j]);

	int ans = 0;
	for (int i = 1; i <= w; ++i) ans = std::max(ans, dp[n][i]);
	std::cout << ans << "\n";
	
	std::function<void(int, int)> dfs = [&](int i, int j) {
		if (i == 0) return;
		for (int k = -2; k <= 2; ++k)
			if (1 <= j + k and j + k <= w)
				if (dp[i][j] == dp[i - 1][j + k] + a[i][j]) {
					dfs(i - 1, j + k);
					std::cout << -k << "\n";
					return;
				}
	};
	for (int i = 1; i <= w; ++i)
		if (dp[n][i] == ans)
			dfs(n, i);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
