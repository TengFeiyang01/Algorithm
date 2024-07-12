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
using PII = std::pair<ll, int>;
const int N = 1e5 + 13;

void solve() {
	int n, c;
	std::cin >> n >> c;

	std::vector<PII> a(n);
	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		a[i] = {std::min(x + i + 1, x + n - i), x + i + 1};
	}

	std::sort(all(a));
	
	std::vector<ll> sum(n + 1);
	for (int i = 0; i < n; ++i) {
		sum[i + 1] = sum[i] + a[i].first;
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i].second <= c) {
			int lo = 0, hi = n;
			while (lo < hi) {
				int x = lo + hi + 1 >> 1;
				ll val = sum[x];
				if (x > i) {
					val -= a[i].first;
				}
				if (val + a[i].second <= c) {
					lo = x;
				} else {
					hi = x - 1;
				}
			}
			ans = std::max(ans, 1 + lo - (lo > i));
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
