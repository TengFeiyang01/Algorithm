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
int n, m, nums[N];

void solve() {
    std::cin>> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    if (a[0] == a[n - 1]) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
        std::reverse(a.begin() + 1, a.end());
        for (int i = 0; i < n; ++i) {
            std::cout << a[i] << " \n"[i == n - 1];
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
