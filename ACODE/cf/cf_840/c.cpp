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
    ll n, a1, a2;
    std::cin >> n;
    if (n == 2) {
    	std::cin >> a1 >> a2;
    	ll ans = 0;
    	ll df = a1 - a2;
    	if (df < 0) df *= -1;
        df *= 2;
        ll sum = a1 + a2;
    	ans = std::max(df, a1 + a2);
    	std::cout << ans << "\n";
    } else if (n > 3) {
        ll mx = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a1;
            mx = std::max(mx, a1);
        }
        std::cout << mx * n << "\n";
    } else {
        ll a3;
        int a[3];
        std::cin >> a[0] >> a[1] >> a[2];
        if (a[1] > a[0] && a[1] > a[2]) {
            std::cout << 2 * a[1] << "\n";
            return;
        }
        if (a[0] > a[1] && a[1] < a[2] && a[0] > a[2]) {
            ll x1 = a[1] + a[2] + a[0];
            ll x2 = 2 * (a[0] - a[1]) + a[2];
            ll x3 = 3 * (a[0] - a[2]);
            ll x4 = std::abs(a[0] - a[1] - a[2]) * 3;
            std::cout << std::max(std::max(x1, x2), std::max(x3, x4)) << "\n";
            return;
        }

        if (a[2] > a[1] && a[2] > a[0] && a[0] < a[1]) {
            ll x1 = a[1] + a[2] + a[0];
            ll x2 = 2 * (a[2] - a[1]) + a[0];
            ll x3 = 3 * (a[2] - a[0]);
            ll x4 = std::abs(a[2] - a[1] - a[0]) * 3;
            std::cout << std::max(std::max(x1, x2), std::max(x3, x4)) << "\n";
            return;
        }
        std::sort(a, a + 3);
        ll ans = 0;
        ans = std::max(3 * (a[2] - a[0]), a[0] + a[1] + a[2]);
        std::cout << ans << "\n";
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
