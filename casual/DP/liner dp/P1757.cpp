#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int m, n;
    std::cin >> m >> n;
    std::vector<i64> dp(m + 1);
    std::map<int, std::vector<std::pair<int, int>>> mp;
    for (int i = 0; i < n; ++i) {
    	int a, b, c;
        std::cin >> a >> b >> c;
        mp[c].push_back({a, b});
    }
    i64 ans = 0;
    for (auto [_, vec] : mp) {
        std::vector<i64> ndp(m + 1);
        for (auto [v, w] : vec) {
            // std::cout << v << " " << w << "\n";
            for (int j = m; j >= v; --j) {
                ndp[j] = std::max(ndp[j], dp[j - v] + w);
                ans = std::max(ans, ndp[j]);
            }
        }
        std::swap(dp, ndp);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
