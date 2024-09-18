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

void solve() {
    ll x, y, z;
    std::cin >> x >> y >> z;
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::vector<std::array<ll, 2>> dp(n + 1);
    dp[0][0] = 0;
    dp[0][1] = z;
    for (int i = 0; i < s.size(); ++i) {
    	if (s[i] == 'a') {
    		dp[i + 1][0] = std::min({dp[i][0] + x, dp[i][1] + x + z, dp[i][1] + y + z, dp[i][0] + z * 2 + y});
    		dp[i + 1][1] = std::min({dp[i][1] + y, dp[i][0] + z + x, dp[i][0] + y + z, dp[i][1] + z * 2 + y});
    	} else {
    		dp[i + 1][0] = std::min({dp[i][0] + y, dp[i][1] + x + z, dp[i][1] + y + z, dp[i][0] + z * 2 + y});
    		dp[i + 1][1] = std::min({dp[i][1] + x, dp[i][0] + z + x, dp[i][0] + y + z, dp[i][1] + z * 2 + y});
    	}
    }
    std::cout << std::min(dp[n][0], dp[n][1]);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
