#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};

void solve() {
    int n, m, sx, sy, k;
    std::cin >> n >> m >> sx >> sy >> k;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> s[i];
    }
    std::vector dp(n, std::vector<int>(m, -inf));
    dp[sx - 1][sy - 1] = 0;
    int ans = 0, tim;

    auto dfs = [&](int x, int y, int l, int tim, int d) {
    	std::deque<std::array<int, 2>> q;
    	for (int i = 0; i < l; ++i, x += dx[d], y += dy[d]) {
    		if (s[x][y] == 'x') q.clear();
    		else {
    			while (!q.empty() && q.back()[0] + i - q.back()[1] <= dp[x][y]) q.pop_back();
    			q.push_back({dp[x][y], i});
    			if (q.front()[1] < i - tim) q.pop_front();
    			dp[x][y] = q.front()[0] + i - q.front()[1];
    			ans = std::max(ans, dp[x][y]);
    		}
    	}
    };

    for (int i = 0; i < k; ++i) {
    	int s, t, d;
    	std::cin >> s >> t >> d;
    	tim = t - s + 1;
    	if (d == 1) for (int i = 0; i < m; ++i) dfs(n - 1, i, n, tim, d);
    	if (d == 2) for (int i = 0; i < m; ++i) dfs(0, i, n, tim, d);
    	if (d == 3) for (int i = 0; i < n; ++i) dfs(i, m - 1, m, tim, d);
    	if (d == 4) for (int i = 0; i < n; ++i) dfs(i, 0, m, tim, d);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
