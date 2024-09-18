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
using PII = std::pair<int, ll>;
const int N = 1e5 + 13;

/*
    https://codeforces.com/contest/1691/submission/189346222

    提示 1：看到  子数组 + min/max， 就要想单调栈。
    对于本题，假设把 a[i] 当作最大值，那么需要得到能把 a[i] 当作最大值的区间左端点的最小值 L，和右端点的最大值 R。这就需要单调栈了。

    提示 2：用前缀和思考。
    需要在 L 到 i 之间选一个最小的前缀和，i 到 R 之间选一个最大的前缀和。这样子数组和才最大。
    如果子数组和 > a[i]，那么输出 NO。
    这可以用 ST 表或者线段树实现。

    还有更快的做法吗？

    提示 3：继续研究，如果从 i-1 向左走，累加元素和，会得到一个 >0 的元素和的话，那么它 + a[i] > a[i]，就要输出 NO 了。
    可以在单调栈出栈的时候，去判断是否有这样的情况。
    为什么只需要考虑单调栈的元素？
    因为其他的下标已经被之前的元素弹出去了，这个下标到 i-1 的元素和必然是 <= 0 的。
    对于从 i+1 向右走的情况也一样，倒序单调栈的同时去判断。
*/

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& v : a) std::cin >> v;
    std::stack<PII> st;
    ll s = 0LL, ok = 1;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && st.top().first <= a[i]) {
            //在这里，栈顶存的是小于当前元素的元素，以及该元素之前的前缀和
            //故若有 st.top().second < s ==> 即 s - st.top().second > 0 即 从该元素到 i - 1 这一段存在大于0的字段，这显然不允许
            if (st.top().second < s) {
                ok = 0;
                break;
            }
            st.pop();
        }
        st.push({a[i], s});
        //std::cout << a[i] << " " << s << "\n";
        s += a[i];
    }

    while (!st.empty()) st.pop();
    s = 0LL;

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && st.top().first <= a[i]) {
            if (st.top().second < s) {
                ok = 0;
                break;
            }
            st.pop();
        }
        st.push({a[i], s});
        s += a[i];
    }

    if (ok) {
        std::cout << "YES\n";
    } else std::cout << "NO\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
