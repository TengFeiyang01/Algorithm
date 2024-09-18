#include <bits/stdc++.h>


#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, k;
    std::cin >> n >> k;
    int x = 0, cur;
    while ((x + 1) * (x + 2) / 2 <= k) x++;

    //前x个正数组成 (x + 1) * x / 2
    //若不够 还需 k - (x + 1) * x / 2 = t 个
    //则此时应该让[l, x + 1] 这个段为正数 1 <= l <= t，此时后面有 x - t个数
    //我们让这x-t个数和当前数组成的子数组小于0即可

    for (int i = 1; i <= n; ++i) {
        if (i <= x) {
            cur = 2;
        } else if (i == x + 1) {
            cur = -2 * (x - (k - (x * (x + 1) / 2))) - 1;
        } else {
            cur = -1000;
        } 
        std::cout << cur << " \n"[i == n];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
