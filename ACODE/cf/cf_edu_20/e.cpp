#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int n, k;
    std::string s;
    std::cin >> n >> k >> s;
    std::vector dp(n + 1, std::vector<int>(2020, -1));
    
    dp[0][n] = 0;

    for (int i = 0; i < n; ++i) {
    	for (int j = n - k + 1; j <= n + k - 1; ++j) {
    		if (~dp[i][j]) {
    			if (s[i] == 'W' or s[i] == '?') {
    				dp[i + 1][j + 1] = j;
    			} 
    			if (s[i] == 'L' or s[i] == '?') {
    				dp[i + 1][j - 1] = j;
    			}
    			if (s[i] == 'D' or s[i] == '?') {
    				dp[i + 1][j] = j;
    			}
    		}
    	}
    }

    if (dp[n][n - k] == -1 and dp[n][n + k] == -1) {
    	std::cout << "NO\n";
    } else {
    	int x = ~dp[n][n - k] ? n - k : n + k;
    	for (int i = n; i > 0; x = dp[i--][x]) {
    		if (dp[i][x] == x - 1) {
    			s[i - 1] = 'W';
    		} else if (dp[i][x] == x + 1) {
    			s[i - 1] = 'L';
    		} else {
    			s[i - 1] = 'D';
    		}
    	}
    	std::cout << s << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}