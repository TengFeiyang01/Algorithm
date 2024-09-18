#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int N = 1010;

long long g[N][N], dp[N][N][4];

void solve() {
    int n, m, q;
    memset(dp, -1, sizeof(dp));
    std::cin >> n >> m >> q;
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		std::cin >> g[i][j];
    	}
    }
    dp[0][0][q] = g[0][0];
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		for (int k = 0; k <= q; ++k) {
    			if (i + 1 < n) {
    				int ok = std::__gcd(g[i + 1][j], g[i][j]) == 1;
    				if (k - ok >= 0 and dp[i][j][k] != -1) {
	    				dp[i + 1][j][k - ok] = std::max(dp[i + 1][j][k - ok], dp[i][j][k] + g[i + 1][j]);
    				}
    			}
    			if (j + 1 < m) {
    				int ok = std::__gcd(g[i][j + 1], g[i][j]) == 1;
    				if (k - ok >= 0 and dp[i][j][k] != -1) {
	    				dp[i][j + 1][k - ok] = std::max(dp[i][j + 1][k - ok], dp[i][j][k] + g[i][j + 1]);
    				}
    			}
    		}
    	}
    }
	long long ans = -1;
	for (int i = 0; i <= q; ++i) ans = std::max(ans, dp[n - 1][m - 1][i]);
	std::cout << ans << "\n";    
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
