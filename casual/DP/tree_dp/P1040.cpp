#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    std::vector dp(n, std::vector<i64>(n, 1));
    std::vector root(n, std::vector<int>(n, 1));
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	dp[i][i] = a[i];
    	root[i][i] = i;
    }

    for (int i = n - 2; i >= 0; --i) {
    	for (int j = i + 1; j < n; ++j) {
    		dp[i][j] = dp[i + 1][j] + dp[i][i];
    		root[i][j] = i;
    		for (int k = i + 1; k < j; ++k) {
    			if (dp[i][k - 1] * dp[k + 1][j] + dp[k][k] > dp[i][j]) {
    				dp[i][j] = dp[k][k] + dp[i][k - 1] * dp[k + 1][j];
    				root[i][j] = k;
    			}
    		}
    	}
    }
    std::cout << dp[0][n - 1] << "\n";
    std::function<void(int, int)> dfs = [&](int l, int r) {
    	if (l > r) return;
    	int rt = root[l][r];
    	std::cout << rt + 1 << " ";
    	dfs(l, rt - 1);
    	dfs(rt + 1, r);
    };
    dfs(0, n - 1);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
