#include <bits/stdc++.h>
 
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
#define YES "YES\n"
#define Yes "Yes\n"
#define NO "NO\n"
#define No "No\n"
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m;
    std::cin>> n >> m;
    std::vector<int> c(n), siz(n);
    std::vector<int> g[n];
    for (int i = 1; i < n; ++i) {
        int fa;
        std::cin >> fa;
        g[fa - 1].push_back(i);
    }
    for (int i = 0; i < n; ++i) std::cin >> c[i];

    std::vector<std::vector<i64>> dp(n, std::vector<i64>(2, -inf));

    std::function<void(int)> dfs = [&](int u) {
        siz[u] = 1;
        dp[u][0] = 0;
        dp[u][1] = c[u];
        for (auto &v : g[u]) {
            dfs(v);
            std::vector<i64> tmp(siz[u] + siz[v] + 1, -inf);
            for (int i = 1; i <= siz[u]; ++i) tmp[i] = dp[u][i];
            for (int i = 1; i <= siz[u]; ++i)
                for (int j = 1; j <= siz[v]; ++j)
                    tmp[i + j] = std::max(tmp[i + j], dp[u][i] + dp[v][j]);
            dp[u] = tmp;
            siz[u] += siz[v];
        }
    };

    dfs(0);
    while (m--) {
        int x, y;
        std::cin >> x >> y;
        x--, y;
        std::cout << dp[x][y] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
