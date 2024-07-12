#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
// double dp[2001][2001][2];

void solve() {
    int n, m, v, e;
    std::cin >> n >> m >> v >> e;
    std::vector<int> c(n + 1), d(n + 1);
    std::vector<double> p(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> c[i];
    }
    for (int i = 1; i <= n; ++i) {
    	std::cin >> d[i];
    }
    for (int i = 1; i <= n; ++i) {
    	std::cin >> p[i];
    }

    std::vector dis(v + 1, std::vector<double>(v + 1, inf));
    for (int i = 1; i <= v; ++i) dis[i][i] = 0;

    for (int i = 0; i < e; ++i) {
    	int x, y, w;
    	std::cin >> x >> y >> w;
    	dis[x][y] = dis[y][x] = std::min(dis[x][y], 1.0 * w);
    }
    // m可能为0 此时需要注意数组范围大小
    std::vector dp(n + 1, std::vector(m + 2, std::vector(2, 1e16)));

    for (int k = 1; k <= v; ++k) {
    	for (int i = 1; i <= v; ++i) {
    		for (int j = 1; j <= v; ++j) {
    			dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
    		}
    	}
    }
    dp[1][0][0] = dp[1][1][1] = 0;
    for (int i = 2; i <= n; ++i) {
    	for (int j = 0; j <= std::min(m, i); ++j) {
    		dp[i][j][0] = std::min(dp[i - 1][j][0] + dis[c[i - 1]][c[i]], 
                                   dp[i - 1][j][1] + dis[c[i - 1]][c[i]] * (1 - p[i - 1]) 
                                                   + dis[d[i - 1]][c[i]] * p[i - 1]);
    		if (j) {
    			dp[i][j][1] = std::min(dp[i - 1][j - 1][0] + dis[c[i - 1]][c[i]] * (1 - p[i]) 
                                                           + dis[c[i - 1]][d[i]] * p[i],
    								   dp[i - 1][j - 1][1] + dis[c[i - 1]][c[i]] * (1 - p[i]) * (1 - p[i - 1])
    								   					   + dis[c[i - 1]][d[i]] * p[i] * (1 - p[i - 1])
    								   					   + dis[d[i - 1]][c[i]] * (1 - p[i]) * p[i - 1]
    													   + dis[d[i - 1]][d[i]] * p[i] * p[i - 1]);
    		}
    	}
    }
    
    double ans = 1e25;
    for (int i = 0; i <= m; ++i) {
        ans = std::min({ans, dp[n][i][0], dp[n][i][1]});
    }
    std::cout << std::fixed << std::setprecision(2) << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
