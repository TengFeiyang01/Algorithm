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
const int N = 1e5 + 13;
int n, m, nums[N];

void solve() {
	std::cin >> n;
	std::vector<PII> v(n);
	int x, y;
	for (auto&[x, y] : v) {
		std::cin >> x >> y;
	}
	sort(v.begin(), v.end());
	int ans = 1;
	auto t = v[0];
	int cnt = 1;
	for (int i = 1; i < n; ++i) {
		if (v[i] == v[i - 1]) {
			cnt++;
			ans = std::max(cnt, ans);
		} else {
			cnt = 1;
		}
	}
	std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
