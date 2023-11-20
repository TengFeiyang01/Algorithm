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
const int N = 113;
int n, m, nums[N];

void solve() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> nums[i];
    int ans = 0;
	std::vector<int> LIS;
	for (int i = 1; i <= n; ++i) {
		if (!LIS.empty() && LIS.back() > nums[i]) {
			*std::lower_bound(LIS.begin(), LIS.end(), nums[i]) = nums[i];
		} else {
			LIS.push_back(nums[i]);
		}
	}
	ans = std::max(ans, (int)LIS.size());
	LIS.clear();
	for (int i = n; i >= 1; --i) {
		if (!LIS.empty() && LIS.back() > nums[i]) {
			*std::lower_bound(LIS.begin(), LIS.end(), nums[i]) = nums[i];
		} else {
			LIS.push_back(nums[i]);
		}
	}
	ans = std::max(ans, (int)LIS.size());
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
