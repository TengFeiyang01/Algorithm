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
    std::vector<ll> a(4);
    ll sum = 0;
    for (int i = 0; i < 4; ++i) std::cin >> a[i], sum += a[i];
    ll ans = 0;
    if (a[0] != 0) {
        ll t = std::min(a[1], a[2]);
        ll tx = std::abs(a[1] - a[2]);
        ans = a[0] + t * 2LL;
        if (a[0] >= a[3]) {
            std::cout << std::min(ans + a[3] + 1 + std::min(a[0] - a[3], tx), sum) << "\n";
        } else {
            std::cout << ans + a[0] + 1LL << "\n";
        }
    } else {
        std::cout << "1\n";
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
