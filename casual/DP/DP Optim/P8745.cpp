#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int mod = 1e9+7;

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::vector dp(n + 1, std::vector<i64>(n + 2));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
    	if (s[i - 1] == '(') {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j - 1];
            }
    	} else {
    		dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) % mod;
    		for (int j = 1; j <= n; ++j) {
    			dp[i][j] = (dp[i - 1][j + 1] + dp[i][j - 1]) % mod;
    		}
    	}
    }
    i64 ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (dp[n][i]) {
            ans = dp[n][i];
            break;
        }
    }

    std::reverse(s.begin(), s.end());
    for (auto &c : s) c ^= 1;
    
    dp.assign(n + 1, std::vector<i64>(n + 2));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
    	if (s[i - 1] == '(') {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j - 1];
            }    
        } else {
    		dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) % mod;
    		for (int j = 1; j <= n; ++j) {
    			dp[i][j] = (dp[i - 1][j + 1] + dp[i][j - 1]) % mod;
    		}
    	}
    }
    i64 res = 0;
    for (int i = 0; i <= n; ++i) {
        if (dp[n][i]) {
            res = dp[n][i];
            break;
        }
    }
    if (!res) {
    	std::cout << ans % mod << "\n";
    } else if (!ans) {
    	std::cout << res << "\n";
    } else {
    	std::cout << 1LL * res * ans % mod << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
