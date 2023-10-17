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
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    a[0] = -inf;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    a.push_back(inf);
    std::vector dp(n + 2, std::vector<int>(n + 1, inf));
	for (int i = 1; i <= n + 1; ++i) {
		for (int j = 0; j <= n; ++j) {
			dp[0][j] = 0;
			if (a[i - 1] < a[i]) dp[i][j] = dp[i - 1][j];
			if (j) {
				for (int k = 0; k < i; ++k) {
					if (a[k] < a[i])
						dp[i][j] = std::min(dp[i][j], dp[k][j - 1] + i - k - 1);
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		std::cout << dp[n + 1][i] << " \n"[i == n];
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
