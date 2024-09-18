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
int n, m, nums[N];

void solve() {
    std::cin >> n;
    std::vector<int> f(n, 1), g(n, 1);
    for (int i = 0; i < n; ++i) std::cin >> nums[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                f[i] = std::max(f[j] + 1, f[i]);
            }
        }
    }
    for (int i = n - 1; i > -1; --i) {
        for (int j = n - 1; j > i; --j) {
            if (nums[i] > nums[j]) {
                g[i] = std::max(g[j] + 1, g[i]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = std::max(f[i] + g[i], ans);
    }
    std::cout << ans - 1 << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
} 