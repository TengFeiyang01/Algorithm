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
const int N = 5e5 + 13;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	auto b = a;
	std::sort(all(b));

	std::vector<int> sum(n + 1);
	for (int i = 0; i < n; ++i) {
		sum[i + 1] = sum[i] + b[i];
	}

	int ans = n + 1;
	for (int x = 1; x <= n; ++x) {
		if (m >= sum[x]) {
			ans = std::min(ans, n - x + 1);
		}
		if (x < n && m >= sum[x] + std::max(a[x] - b[x - 1], 0)) {
			ans = std::min(ans, std::max(1, n - x));
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
