#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>
#include <stack>
#include <numeric>
#include <cmath>

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
    std::vector<ll> a(n + 1);
    ll s = 0LL;
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    	s += a[i];
    }
  	std::vector dp(n, std::vector<ll>(2, -inf));
	//dp[0]表示不翻转， dp[1]表示翻转

	dp[1][0] = a[1] + a[2];
	dp[1][1] = -a[1] - a[2];

	for (int i = 2; i < n; ++i) {
		dp[i][1] = std::max(dp[i - 1][0] - 2 * a[i] - a[i + 1], dp[i - 1][1] + 2 * a[i] - a[i + 1]);
		dp[i][0] = std::max(dp[i - 1][0] + a[i + 1], dp[i - 1][1] + a[i + 1]);
	}
	std::cout << std::max(dp[n - 1][0], dp[n - 1][1]) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
