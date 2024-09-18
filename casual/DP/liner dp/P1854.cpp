#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector a(n, std::vector(m, 0));
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		std::cin >> a[i][j];
    	}
    }

    std::vector dp(n, std::vector<int>(m, -inf));
    std::vector pre(n, std::vector<int>(m));

    for (int i = i; i < m - n; ++i) {
    	dp[0][i] = a[0][i];
        pre[0][i] = i;
    }

    for (int i = 1; i < n; ++i) {
        // 当前在第 i 行 那么包括当前在内还有n-i行 那么包括j在内至少也得有n-i行 j最大可取 m-(n-i) 
    	for (int j = i; j <= m - n + i; ++j) { 
    		for (int k = 0; k < j; ++k) {  //
    			if (dp[i][j] < dp[i - 1][k] + a[i][j]) {
    				dp[i][j] = dp[i - 1][k] + a[i][j];
    				pre[i][j] = k;
    			}
    		}
    	}
    }
    int ans = -inf, la = -1;
    for (int i = n - 1; i < m; ++i) {
    	if (dp[n - 1][i] > ans) {
    		ans = dp[n - 1][i];
    		la = i;
    	}
    }
    std::vector<int> path{la};
    for (int i = n - 1; i > 0; --i) {
    	path.push_back(pre[i][la]);
    	la = pre[i][la];
    }
    std::cout << ans << "\n";
    for (int x : std::views::reverse(path)) {
    	std::cout << x + 1 << " ";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
