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
    std::string a, b;
    std::cin >> a >> b;
    int n = sz(a), m = sz(b);
    int st = 0, alf = 0;
    int ans = 0;
	if (n > m) {
		std::swap(n, m);
		std::swap(a, b);
	}
	if (a == b) {
		std::cout << "YES\n";
		std::cout << a << "\n";
		return;
	}

	if (a[0] == b[0] && m > 1) {
		std::cout << "YES\n";
		std::cout << a[0] << "*\n";
		return;
	} 
	if (a.back() == b.back() && m > 1) {
		std::cout << "YES\n";
		std::cout << "*" << a.back() << "\n";
		return;
	}

	std::string t;
	std::vector dp(n + 1, std::vector<int>(m + 1, 0));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (dp[i][j] > ans) {
					ans = dp[i][j];
					t = a.substr(i - ans, ans);
				}
			} else {
				dp[i][j] = 0;
			}
		}
	if (ans >= 2) {
		std::cout << "YES\n";
		std::cout << "*" << t << "*" << "\n";
		return;
	}
	std::cout << "NO\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
