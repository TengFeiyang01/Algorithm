#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a, op;
    for (int i = 0; i < 2 * n; ++i) {
    	if (i % 2) {
    		int x;
    		std::cin >> x;
    		a.push_back(x);
    	} else {
    		char c;
    		std::cin >> c;
    		if (c == 't') {
    			op.push_back(1);
    		} else {
    			op.push_back(2);
    		}
    	}
    }
    
    for (int i = 0; i < n; ++i) a.push_back(a[i]);
    for (int i = 0; i < n; ++i) op.push_back(op[i]);

    std::vector dp(n << 1, std::vector(n << 1, std::vector(2, 0)));
	for (int i = n * 2 - 2; i >= 0; --i) {
		dp[i][i][0] = dp[i][i][1] = a[i];
		for (int j = i + 1; j < 2 * n; ++j) {
			dp[i][j][0] = inf; dp[i][j][1] = -inf;
			for (int k = i; k < j; ++k) {
				if (op[(k + 1) % (n * 2)] == 1) {
					dp[i][j][0] = std::min(dp[i][j][0], dp[i][k][0] + dp[k + 1][j][0]);
					dp[i][j][1] = std::max(dp[i][j][1], dp[i][k][1] + dp[k + 1][j][1]);
				} else {
					dp[i][j][0] = std::min(dp[i][j][0], dp[i][k][0] * dp[k + 1][j][0]);
					dp[i][j][0] = std::min(dp[i][j][0], dp[i][k][0] * dp[k + 1][j][1]);
					dp[i][j][0] = std::min(dp[i][j][0], dp[i][k][1] * dp[k + 1][j][0]);
					dp[i][j][0] = std::min(dp[i][j][0], dp[i][k][1] * dp[k + 1][j][1]);
					dp[i][j][1] = std::max(dp[i][j][1], dp[i][k][1] * dp[k + 1][j][1]);
					dp[i][j][1] = std::max(dp[i][j][1], dp[i][k][1] * dp[k + 1][j][0]);
					dp[i][j][1] = std::max(dp[i][j][1], dp[i][k][0] * dp[k + 1][j][1]);
					dp[i][j][1] = std::max(dp[i][j][1], dp[i][k][0] * dp[k + 1][j][0]);
				}
			}
		}
	}
	int ans = -inf;
	for (int i = 0; i < n; ++i) {
		ans = std::max(ans, dp[i][i + n - 1][1]);
	}
	std::cout << ans << "\n";
	for (int i = 0; i < n; ++i) {
		if (dp[i][i + n - 1][1] == ans) {
			std::cout << i + 1 << " ";
		}
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
