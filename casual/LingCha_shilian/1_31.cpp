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


/*
https://codeforces.com/contest/797/submission/190439455

    考虑有多少个节点值可以找到。
    参考 https://www.bilibili.com/video/BV14G411P7C1/ 的方法一，把合法查询范围作为递归参数传下去。
    如果节点值 x 在范围内，则有 cnt[x] 个 x 可以找到。

    注：用 cnt 是因为有重复的节点，这些节点值都可以找到（即使某些节点无法访问到）。

*/

struct Node {
    int val, left, right;
}tr[N];

void solve() {
    std::map<int, int> cnt;
    int n, x, l, r;
    std::cin >> n;
    std::vector<int> idg(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        std::cin >> x >> l >> r;
        if (l != -1) idg[l]++;
        if (r != -1) idg[r]++;
        cnt[x]++;
        tr[i].val = x;
        tr[i].left = l;
        tr[i].right = r;
    }

    int root = -1;
    for (int i = 1; i <= n; ++i) {
        if (idg[i] == 0) {
            root = i;
            break;
        }
    }
    int ans = n;

    auto dfs = [&](auto self, int node, int left, int right) {
        if (node == -1) return;
        int x = tr[node].val;
        if (left <= x && x <= right) ans -= cnt[x];
        if (left < x) self(self, tr[node].left, left, std::min(right, x - 1));
        if (x < right) self(self, tr[node].right, std::max(left, x + 1), right);
    };
    dfs(dfs, root, 0, 1e9);
    std::cout << ans << "\n";
}


int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
