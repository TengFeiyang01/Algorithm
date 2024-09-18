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


/*
    https://codeforces.com/contest/1661/submission/190218911

    提示 1：最终高度只能是 max(h) 和 max(h)+1，更高的高度只会比这两个的天数多。

    提示 2：为什么可以是 max(h)+1？因为两个 1 可以当成 2，而 2 无法当作 1。
    例如 h=[1,1,1,1,1,1,2]，max(h) 需要 11 天，而 max(h)+1 需要 9 天。

    提示 3：贪心，或者二分答案。二分答案的 check 是需要补奇数的树必须用个+1，其他的随意，所以先用 +1，然后看剩下的能否补到所有高度都一样。

    贪心的做法是分类讨论，记 c1 表示需要补奇数高度的树的个数，c2 为每棵树需要补充的高度除以 2 下取整之和：
    - 如果 c1>c2，那么需要 c1*2-1 天。
    - 如果 c1=c2，那么需要 c2*2 天。
    - 如果 c1<c2，例如 12_2_2_2 这种，可以把空出的前两个 1 补到最后一个 2 上，这样只需要 6 天。
    总的来说需要研究 _2_2_2... 这种需要多少天，你可以手玩下推出这个长度在模 3=0/1/2 时有不同的结果。
    设 d = (c2-c1)*2，那么前面的 1212... 需要 c1*2 天，后面的 _2_2_2... 需要 d/3*2+d%3 天。
*/

void solve() {
   	int n;
   	std::cin >> n;
   	std::vector<ll> a(n);
   	for (int i = 0; i < n; ++i) std::cin >> a[i];
   	ll x = *std::max_element(all(a));
   	auto f = [&](ll x) ->ll {
        ll c1 = 0, c2 = 0;
        for (auto v : a) {
            v = x - v;
            c1 += v % 2;
            c2 += v / 2;
        }
        if (c1 > c2) {
            return c1 * 2 - 1LL;
        } else if (c1 == c2) {
            return c1 * 2LL;
        } else {
            c2 = (c2 - c1) * 2;
            return c1 * 2 + c2 / 3 * 2 + c2 % 3;
        }
    };
    std::cout << std::min(f(x), f(x + 1)) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
