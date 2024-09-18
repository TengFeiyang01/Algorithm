#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::cin >> m;
    std::vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }

    std::vector dp(n + 1, std::vector(m + 1, 0));
    std::vector pre(n + 1, std::vector(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        int mx = 0, pos = 0;
        for (int j = 1; j <= m; ++j) {
            pre[i][j] = j;
            if (a[i - 1] == b[j - 1]) {
                if (dp[i][j] < mx + 1) {
                    dp[i][j] = mx + 1;
                    pre[i][j] = pos;
                }
            } else {
                dp[i][j] = dp[i - 1][j];
            }
            if (b[j - 1] < a[i - 1]) {
                if (dp[i - 1][j] > mx) {
                    mx = dp[i - 1][j];
                    pos = j;
                }
            }
        }
    }

    // O(n^3)写法 不难发现 k的决策的是递增的
/*    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= m; ++j) {
    		if (a[i - 1] == b[j - 1]) {
    			int mx = 0;
    			for (int k = 1; k < i; ++k) {
    				if (a[k - 1] < a[i - 1])
	    				mx = std::max(mx, dp[k][j - 1]);
    			}
    			dp[i][j] = std::max(dp[i][j], mx + 1);
    		} else {
    			dp[i][j] = dp[i - 1][j];
    		}
    	}
    }*/
    int final = 0, ans = 0;
    for (int i = 1; i <= m; ++i) {
        if (dp[n][i] > ans) {
            ans = dp[n][i];
            final = i;
        }
    }
    std::cout << ans << "\n";
    std::vector<int> path;
    if (!ans) return;
    for (int i = n, j = final; i or j; --i) {
        if (pre[i][j] != j) {
            path.push_back(b[j - 1]);
        }
        j = pre[i][j];
    }
    for (auto x : std::views::reverse(path)) std::cout << x << " ";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
