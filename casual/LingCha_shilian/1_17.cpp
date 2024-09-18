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
    https://codeforces.com/problemset/problem/1409/E
    https://codeforces.com/contest/1409/submission/189420578

    先排序。

    如果只有一个线段，那就是双指针问题。

    两个线段的话，第二个线段用双指针，顺带加上 left 之前的最大覆盖数，则需要额外维护一个覆盖数的前缀最大值。

    具体来说，pre[i] 记录以 i-1 结尾的单个线段的最大覆盖数，那么有
        ans = max(ans, right-left+1+pre[left])
        pre[right+1] = max(pre[right], right-left+1)
    这里 left 和 right 是双指针里面的变量。

*/

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
   	for (int i = 0; i < n; ++i) std::cin >> b[i];
   	std::vector<int> pre(n + 1, 0);
   	
    std::sort(all(a));

   	int ans = 0;
   	for (int left = 0, right = 0; right < n; ++right) {
   		while (a[right] - a[left] > k) left++;

   		ans = std::max(ans, right - left + 1 + pre[left]);
   		pre[right + 1] = std::max(pre[right], right - left + 1);
   	}
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
