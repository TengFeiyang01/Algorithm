#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int mod = 1000000007;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::vector<std::vector<i64>> dp(n, std::vector<i64>(26));
    dp[0][a[0]] = 1;
    for (int i = 1; i < n; ++i) {
    	for (int j = 0; j < 26; ++j) {
            if (a[i]) {
                if (j - a[i] >= 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - a[i]]) % mod;
                } 

                if (j + a[i] < 26) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + a[i]]) % mod;
                }     
            } else {
                dp[i][j] = dp[i - 1][j];
            }
    		
    	}
    }
    i64 ans = 0;
    for (int i = 0; i < 26; ++i) {
    	ans = (ans + dp[n - 1][i]) % mod;
    }
    std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
