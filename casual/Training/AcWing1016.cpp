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

using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
int n, m, nums[N];

void solve() {
    std::cin >> n;
    for (int i = 0; i < n; ++i) std::cin >> nums[i];
    std::vector<int> f(n);
	
	int ans = 0;

	for (int i = 0; i < n; ++i) {
		f[i] = nums[i];
		for (int j = 0; j < i; ++j) {
			if (nums[j] < nums[i]) {
				f[i] = std::max(f[i], f[j] + nums[i]);
			}
		}
		ans = std::max(ans, f[i]);
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
