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
const int mod = 1e9 + 7;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    std::vector dp(n + 1, std::vector<ll>(64));
    for (int i = 0; i < n; ++i) std::cin >> a[i];

    for (int i = 1; i <= n; ++i) {
    	for (int j = 0; j <= 63; ++j) {
    		dp[i][j] = dp[i - 1][j];
    		dp[i][j & a[i - 1]] += dp[i - 1][j];
    		dp[i][j] %= mod;
    		dp[i][j & a[i - 1]] %= mod;
    	}
    	dp[i][a[i - 1]] += 1LL;
    	dp[i][a[i - 1]] %= mod;
    }
    
    ll ans = 0;
    for (int i = 0; i <= 63; ++i) {
        int cnt = 0, t = i;
        while (t) {
            t &= t - 1;
            cnt += 1;
        }
        if (cnt == k) {
            ans = (ans + dp[n][i]) % mod;
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
