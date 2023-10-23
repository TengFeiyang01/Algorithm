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
ll n, x;


/*提示 1：看成是环形数组，那么数组复制一份接在后面，就变成非环形的了（注意 x 不超过 sum(d)）。

提示 2：这是个窗口大小为 x 的滑窗问题，但是 x 太大了，如何优化？

提示 3：窗口的开头或者末尾只需要在某些关键的 day 就行了，是什么样的 day 呢？

提示 4：月末收益最大。

提示 5：窗口末尾只需要在月末就行。可以用反证法证明：
假设窗口末尾不在月末是最优的，设末尾在第 k 天，那么右边一定是第 k+1 天。
如果窗口向右滑，由于我们假设不在月末更优，因此窗口的元素和减少，
所以从左边出去的元素必然大于 k+1，出去的元素的左边那个元素必然大于 k。那么把窗口改为向左滑，
窗口左边进来一个大于 k 的数，右边出去一个等于 k 的数，窗口元素和变大，矛盾，因此窗口末尾一定在月末是最优的。

那么在倍增后 d 数组上双指针模拟就好了。*/

void solve() {
    std::cin >> n >> x;
    std::vector<ll> d(n * 2);

    for (int i = 0; i < n; ++i) std::cin >> d[i], d[i + n] = d[i];

    ll l = 0, s = 0, s2 = 0, ans = 0;
	
	for (auto v : d) {
		s += v;
		s2 += (v + 1) * v / 2;
		while (s > x) {
			s -= d[l];
			s2 -= (d[l] + 1) * d[l] / 2;
			l++;
		}
		if (l > 0) {
			ll c = x - s;
			ans = std::max(ans, s2 + (d[l - 1] * 2 - c + 1) * c / 2);
		} else {
			ans = std::max(ans, s2);
		}
	}
	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
