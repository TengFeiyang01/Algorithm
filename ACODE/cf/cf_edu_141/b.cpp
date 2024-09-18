#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <cstring>
#include <map>
#include <unordered_map>

const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e2 + 13;
//using vector = std::vector<std::vector<int>>;

//必定可以构造出1 - n * n - 1, 类似于 1 - n 构造 1 - n - 1
//我们令l = 1, r = n * n, 链状构造即可

void solve() {
    int n;
    std::cin >> n;

    std::vector a(n, std::vector<int>(n));
    int l = 1, r = n * n;
    int t = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = t ? l++ : r--;
            t ^= 1;
        }
        if (i & 1) std::reverse(a[i].begin(), a[i].end());
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << a[i][j] << " \n"[j == n - 1];
        }
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
