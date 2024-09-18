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
ll n, m, nums[N];

void solve() {
    std::cin >> n;
    ll f = 0;
    std::cin >> f;
    for (int i = 0; i < n - 1; ++i)
    	std::cin >> nums[i];
    std::sort(nums, nums + n - 1);

    for (int i = 0; i < n - 1; ++i) {
    	int x = (nums[i] - f) / 2;
    	if (f < nums[i]) {
    		f += ((nums[i] - f) % 2) ? x + 1 : x;
    	}
    }
    std::cout << f << "\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
