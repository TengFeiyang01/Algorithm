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

const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
int n, m;

void solve() {
    ll ans = 0, x = 0;
    std::vector<int> v;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    std::vector<int> op;
    for (int i = 0; i < m; ++i) {
        std::cin >> x;
        op.push_back(x);
    }
    for (int i : op) {
        bool t = false;
        for (int j = 0; j < n; ++j) {
            if (i > v[j]) {
                v[j] = i;
                t = true;
                break;
            }
        }
        if (!t) {
            v[0] = i;
            std::sort(v.begin(), v.end());
        } else {
            t = false;
            std::sort(v.begin(), v.end());
        }
    }
    for (int i : v) ans += i;
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
