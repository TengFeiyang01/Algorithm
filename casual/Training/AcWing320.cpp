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

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> w(n << 1 | 1);
    vector f(n << 1 | 1, std::vector<int>(n << 1 | 1, 0));
    for (int i = 1; i <= n; ++i) std::cin >> w[i], w[i + n] = w[i];

    //len = 2表示只有一颗珠子
    //初始长度从两颗珠子 寄 len = 3

    for (int len = 3; len <= n + 1; ++len)
        for (int l = 1; l + len - 1 <= n << 1; ++l) {
            int r = l + len - 1;
            for (int k = l + 1; k < r; ++k) {
                f[l][r] = std::max(f[l][r], f[l][k] + f[k][r] + w[l] * w[r] * w[k]);
            }
        }
    int ans1 = 0;
    for (int i = 1; i <= n; ++i) {
        ans1 = std::max(ans1, f[i][i + n]);
    }
    std::cout << ans1 << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
