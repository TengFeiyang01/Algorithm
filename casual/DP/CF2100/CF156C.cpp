#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
const int mod = 1000000007;

void solve() {
    int n;
    std::cin >> n;
    std::vector dp(101, std::vector<i64>(101 * 26));
    dp[0][0] = 1;
    for (int i = 1; i <= 100; ++i) {
    	for (int j = i; j <= 26 * i; ++j) {
    		for (int k = 1; k <= 26 and k <= j; ++k) {
    			dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
    		}
    	}
    }

    while (n--) {
    	std::string s;
    	std::cin >> s;
    	int n = s.size(), sum = 0;
    	std::ranges::for_each(s, [&](char &c) { sum += c - 'a' + 1; } );
    	std::cout << (dp[n][sum] - 1 + mod) % mod << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
