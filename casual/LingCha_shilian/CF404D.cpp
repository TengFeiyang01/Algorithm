#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

const int MOD = 1000000007;

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    s = " " + s;
    std::vector dp(n + 1, std::vector<int>(5, 0));
    dp[0][0] = dp[0][2] = 1;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '*' or s[i] == '?') {
            dp[i][4] = (dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][3]) % MOD;
        } 
        if (s[i] == '0' or s[i] == '?') {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD; 
        }
        if (s[i] == '2' or s[i] == '?') {
            dp[i][3] = dp[i - 1][4];
        }
        if (s[i] == '1' or s[i] == '?') {
            dp[i][1] = dp[i - 1][4];
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        }
    }
    std::cout << (dp[n][0] + dp[n][1] + dp[n][4]) % MOD << "\n";
}

#if 0
void solve() {
    std::string s;
    std::cin >> s;
    i64 f0 = 1, f1 = 0, f2 = 1;
    for (char c : s) {
    	switch (c) {
    	case '0':
    		f1 = 0, f2 = 0;
    		break;
    	case '1':
    		f2 = f0;
    		f0 = f1;
    		f1 = 0;
            break;
    	case '2':
    		f2 = f1;
    		f0 = f1 = 0;
            break;
    	case '*':
    		f0 = 0;
    		f1 = f2;
            break;
    	default:
    		i64 tmp = f0 + f1;
    		f0 = tmp % MOD;
    		f1 = f2;
    		f2 = (tmp + f2) % MOD;
    	}
    }
    std::cout << (f0 + f1) % MOD << "\n";
}
#endif

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
