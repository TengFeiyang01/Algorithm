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
const int N = 1e2 + 13;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector a(N, std::vector<char>(N));
    std::vector dp(N, std::vector<ll>(N));
    for (int i = 0; i < n; ++i)
    	for (int j = 0; j <= i; ++j)
    		std::cin >> a[i][j];

    dp[0][0] = 1LL;
    for (int i = 0; i < n; ++i)
    	for (int j = 0; j <= i; ++j)
    		if (a[i][j] == '*') {
    			dp[i + 1][j] += dp[i][j];
    			dp[i + 1][j + 1] += dp[i][j];
    		} else {
    			dp[i + 2][j + 1] += dp[i][j] * 4; //直接穿过了两层
    		}
    ll sum = 1LL << n;
    ll w = std::__gcd(sum, dp[n][m]);
    std::cout << dp[n][m] / w << "/" << sum / w << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
