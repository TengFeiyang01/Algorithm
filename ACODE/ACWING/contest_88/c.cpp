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
using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

int a[120];
int dp[120][3];
int n;

void solve() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    memset(dp, 0x3f, sizeof dp);

	if (a[1] == 1) dp[1][0] = 0;
	if (a[1] == 2) dp[1][1] = 0;
	if (a[1] == 3) dp[1][0] = dp[1][1] = 0;
	
	dp[1][2] = 1;

	for (int i = 2; i <= n; ++i) {
		if (a[i] == 1) {
			dp[i][0] = std::min(dp[i - 1][1], dp[i - 1][2]);
		}
		if (a[1] == 2) 
			dp[i][2] = std::min(dp[i - 1][0], dp[i - 1][2]);
		if (a[i] == 3) {
			dp[i][0] = std::min(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][2]);
		}
		dp[i][2] = 1 + std::min(dp[i - 1][0], std::min(dp[i - 1][1], dp[i - 1][2]));
	}
	
	std::cout << std::min(dp[n][0], std::min(dp[n][1], dp[n][2]));
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
