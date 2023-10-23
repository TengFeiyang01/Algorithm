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
int n, m, nums[N], k;

/*直接二分答案，O(n) check ，check时只需要保证能构造出子序列满足 x（二分的数字） 在奇数序号或者偶数序号中是最大（都小于等于x）的即可*/

void solve() {
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i) std::cin >> nums[i];
    auto check = [&](int c, int up)->bool{
    	int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!c) ans++, c ^= 1;
            else {
                if (nums[i] <= up) ans++, c ^= 1;
            }
        }
    	return ans >= k;
    };
    int l = 1, r = 1e9;
    while (l < r) {
    	int mid = l + r >> 1;
    	if (check(1, mid) || check(0, mid)) r = mid;
    	else l = mid + 1;
    }
    std::cout << l << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
