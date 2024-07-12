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
    std::cin >> n;
    if (n % 2 == 0) {
        std::cout <<"YES\n";
        for (int i = 0; i < n / 2; ++i) {
            std::cout << "1 -1 ";
        }
        std::cout << "\n";
    } else if (n == 3) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
        int x = n / 2;
        for (int i = 0; i < n / 2; ++i) {
            std::cout << 1 - x << " " << x << " ";
        }
        std::cout << 1 - x << "\n";
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
