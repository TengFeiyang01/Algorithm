#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int h, w, n;
    std::cin >> h >> w >> n;
    std::vector hole(h, std::vector<bool>(w));

    while (n--) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        hole[a][b] = true;
    }

    std::vector dp(h, std::vector<int>(w)); 
    i64 ans = 0;
    for (int i = 0; i < h; ++i) {
    	for (int j = 0; j < w; ++j) {
    		dp[i][j] = i && j ? std::min(dp[i][j - 1], dp[i - 1][j]) + 1 : 1;
            if (hole[i - dp[i][j] + 1][j - dp[i][j] + 1]) {
                dp[i][j]--;
            }
    		if (hole[i][j]) {
    			dp[i][j] = 0;
    		}
    		ans += dp[i][j];
    	}
    }
    
    std::cout << ans << "\n";
}


int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
