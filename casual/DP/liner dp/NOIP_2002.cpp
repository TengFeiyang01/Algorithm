#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
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
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void solve() {
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;
    std::vector dp(n + 1, std::vector<ll>(m + 1));
    dp[0][0] = 1LL;
    std::set<PII> ban;
    ban.insert({x, y});
    for (int i = 0; i < 8; ++i) {
    	ban.insert({x + dx[i], y + dy[i]});
    }
    
    for (int i = 0; i <= n; ++i)
    	for (int j = 0; j <= m; ++j) {
            if (ban.count({i, j}) or (i == 0 and j == 0)) continue;
            if (i) dp[i][j] += dp[i - 1][j];
            if (j) dp[i][j] += dp[i][j - 1];
        }
        
    std::cout << dp[n][m];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
