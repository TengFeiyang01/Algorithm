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
const int N = 1e3 + 13;


void solve() {
	int n, m;
	std::cin >> m >> n;
	std::vector a(m, std::vector<int>(n));
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) 
			std::cin >> a[i][j];
	if ((m + n) % 2 == 0) {
		std::cout << "NO\n";
		return;
	}
	std::vector<int> mn(n + 1, inf), mx(n + 1, -inf);
	mn[0] = 0, mx[0] = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			mn[j + 1] = std::min(mn[j + 1], mn[j]) + a[i][j];
			mx[j + 1] = std::max(mx[j + 1], mx[j]) + a[i][j];
		}
		mn[0] = inf, mx[0] = -inf;
	}
	if (mn[n] > 0 || mx[n] < 0) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n";
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
