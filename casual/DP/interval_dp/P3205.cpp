#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    //dp[i][j] 最后一个进来的人是i 从左边进来的
    //f[i][j] 最后一个进来的人是j 从右边进来的
    std::vector dp(n, std::vector(n, 0));
    std::vector f(n, std::vector(n, 0));
    for (int i = 0; i < n; ++i) {
    	f[i][i] = 1;
    	std::cin >> a[i];
    }
    const int mod = 19650827;
    for (int i = n - 2; i >= 0; --i) {
    	for (int j = i + 1; j < n; ++j) {
    		if (a[i] < a[i + 1]) {
    			dp[i][j] += dp[i + 1][j];
    		}
    		// a[i] < a[j] 此时第j个人进来 他比a[i]大 她进去右边
    		if (a[i] < a[j]) {
    			dp[i][j] += f[i + 1][j];
    			f[i][j] += dp[i][j - 1];
    		}
    		if (a[j] > a[j - 1]) {
    			f[i][j] += f[i][j - 1];
    		}
    		dp[i][j] %= mod;
    		f[i][j] %= mod;
    	}
    }
    std::cout << (dp[0][n - 1] + f[0][n - 1]) % mod;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
