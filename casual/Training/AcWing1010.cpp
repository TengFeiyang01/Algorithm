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
int f[N], g[N];

void solve() {
    int x, len = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        int pos1 = std::upper_bound(f, f + len, x, std::greater<int>()) - f;
        if (pos1 == len) f[len++] = x;
        else f[pos1] = x;


        int pos2 = std::lower_bound(g, g + res, x) - g;
        if (pos2 == res) g[res++] = x;
        else g[pos2] = x;
    }
    std::cout << len << "\n" << res;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
