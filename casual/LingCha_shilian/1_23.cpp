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

void solve() {
    ll n, k;
    std::cin >> n >> k;
    ll d = 0LL, d2[n]{0}, b[n]{0};
    for (int i = 0; i < n; ++i) std::cin >> b[i];

    ll ans = 0LL, s = 0LL;

	for (int i = n - 1; i >= 0; --i) {
		d += d2[i];
		s += d;
		if (s < b[i]) {
			ll k2 = std::min(k, i + 1LL);
			ll times = (b[i] - s + k2 - 1LL) / k2;
			ans += times;
			s += times * k2;
			if (i > 0) {
				d2[i - 1] -= times;
				if (i > k2) {
					d2[i - k2 - 1] += times;
				}
			}
		}
	}
	std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    solve();

    return 0;
}
