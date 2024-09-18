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

const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 2e5 + 13;
int n, m, a[N];
ll sum[N];

void solve() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	ll ans = 0;
	for (int i = 1; i < n; ++i) {
		ans += a[i] * (sum[n] - sum[i]);
	}

	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
