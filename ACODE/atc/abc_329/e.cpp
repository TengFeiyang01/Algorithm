#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

// 也可以暴力搜索 匹配的盖住 
void solve() {
    int n, m;
    std::string s, t;
    std::cin >> n >> m >> s >> t;
    std::vector dp(n, std::vector<bool>(m, false));
    dp[0][0] = s[0] == t[0];
    for (int i = 1; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		if (dp[i - 1][j]) {
    			dp[i][0] = s[i] == t[0];
    		}
    	}
    	for (int j = 1; j < m; ++j) {
    		if (i >= j and dp[i - 1][j - 1] and s[i] == t[j]) dp[i][j] = true;
    		if (i >= m and dp[i - 1][m - 1] and s[i] == t[j]) dp[i][j] = true;
    	}
    }
    if (dp[n - 1][m - 1]) {
    	std::cout << "Yes\n";
    } else {
    	std::cout << "No\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
