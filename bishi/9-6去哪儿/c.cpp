#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> dp(n + 1);
    for (int i = 0; i < n; ++i) {
    	int cnt[10]{0}, mx = 0, tot = 0;
    	for (int j = i; j >= 0; --j) {
    		cnt[s[j] - '0']++;
    		int g = 0;
            for (int k = 0; k <= 9; ++k) {
                g = std::__gcd(g, cnt[k]);
            }
            if (g >= 2) {
                dp[i + 1] = std::max(dp[i + 1], dp[j] + 1);
            }
    	}
    }
    std::cout << dp[n] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
