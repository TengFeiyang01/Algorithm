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
const int N = 1e2 + 13;
ll n, m;

void solve() {
    std::cin >> n;
    ll nums[N];

    for (ll i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    std::sort(nums, nums + n);
    for (int i = 1; i < n; ++i)
        if (nums[i] == nums[i - 1]) {
            std::cout << "NO\n";
            return;
        }
    auto check = [&](int k) {
        std::vector<ll> v(k);
        for (int i = 0; i < n; ++i) {
            v[nums[i] % k]++;
        }
        for (int c : v) if (c < 2) return false;
        return true;
    };
    for (int i = 2; i <= 51; ++i)
        if (check(i)) {
            std::cout << "NO\n";
            return;
        }
    std::cout << "YES\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
