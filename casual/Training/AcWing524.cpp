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
using PII = std::pair<double, double>;
const int N = 1e5 + 13;
const double eps = 1e-6;

bool cmp(double x, double y) {
    if (fabs(x - y) < eps) return false;
    return true;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<PII> points(n);
    for (auto&[x, y] : points) std::cin >> x >> y;

    vector path(n, std::vector<int>(n));

    std::vector<int> f(1 << n, inf);

    for (int i = 0; i < n; ++i) {
        path[i][i] = 1 << i;
        for (int j = 0; j < n; ++j) {
            auto[x1, y1] = points[i];
            auto[x2, y2] = points[j];
            if (!cmp(x1, x2)) continue;
            double a = (y1 / x1 - y2 / x2) / (x1 - x2);
            double b = y1 / x1 - a * x1;
            if (a > 0) continue;
            int state = 0;
            for (int k = 0; k < n; ++k) {
                auto[x, y] = points[k];
                if (!cmp(a * x * x + b * x, y)) state += 1 << k;
            }
            path[i][j] = state;
        }
    }

    f[0] = 0;

    for (int i = 0; i + 1 < 1 << n; ++i) {
        int x = 0;
        for (int j = 0; j < n; ++j) {
            if (!(i >> j & 1)) {
                x = j;
                break;
            }
        }
        for (int j = 0; j < n; ++j) {
            f[i | path[x][j]] = std::min(f[i | path[x][j]], f[i] + 1);
        }
    }
    std::cout << f[(1 << n) - 1] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
