#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> w(n + 1, std::vector<int>(m + 1));
    std::vector<int> dp(m + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std::cin >> w[i][j];

    for (int i = 1; i <= n; ++i)
    	for (int j = m; j >= 0; --j)
            for (int k = 0; k <= j; ++k) 
                dp[j] = std::max(dp[j], dp[j - k] + w[i][k]);

    std::cout << dp[m];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
