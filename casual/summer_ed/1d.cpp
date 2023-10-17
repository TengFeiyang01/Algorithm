#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
int cnt = 1;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> g[n], a(n), dp(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        std::cin >> x >> y;
        g[x - 1].emplace_back(y - 1);
        g[y - 1].emplace_back(x - 1);
    }

    std::function<int(int)> dfs = [&](int u) ->int {
        if (dp[u]) return dp[u];
        dp[u] = 1;
        for (int &v : g[u]) {
            if (a[u] > a[v]) dp[u] += dfs(v);
        }
        return dp[u];
    };

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (dp[i]) ans = std::max(ans, dp[i]);
        else {
            ans = std::max(ans, dfs(i));
        }
    }

    std::cout << "Case #" << cnt++ << ": " << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
