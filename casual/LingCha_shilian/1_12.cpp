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
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

/*https://codeforces.com/contest/1490/submission/108014953

提示 1：计算 a 的前缀和的所有 record 下标 p（record 指比上一个最大值更大的前缀和的下标）。
因为前缀和中任何一个递减或相同的地方都是不重要的。

提示 2：做一些与 x 大小有关的分类讨论，在 p 上二分。*/

void solve() {
    int n, x, m;
    std::cin >> n >> m;
    std::vector<int> p(1, 0);
    std::vector<i64> sum(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        std::cin >> x;
        sum[i] = sum[i - 1] + x;
        if (sum[i] > sum[p.back()]) {
            p.pb(i);
        }
    }
    auto serach = [&](int x) ->int{
        int l = 0, r = sz(p) - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (sum[p[mid]] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    while (m--) {
        std::cin >> x;
        if (x <= sum[p.back()]) {
            int i = serach(x);
            std::cout << p[i] - 1 << " ";
        } else if (sum[n] < 1) {
            std::cout << "-1 ";
        } else {
            int loop = (x - sum[p.back()] - 1) / sum[n] + 1;
            x -= loop * sum[n];
            int i = serach(x);
            std::cout << (i64)loop * n + (i64)(p[i] - 1) << " ";
        }
    }
    std::cout << "\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
