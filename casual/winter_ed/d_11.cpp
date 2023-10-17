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
#define PQ priority_queue

const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<ll, ll>;
const int N = 1e5 + 13;
int n, m, a[N], b[N];

ll sum(int r, int n, int t) {
    int l = r - t * (n - 1);
    return ll(l + r) * n >> 1;
}

bool check(int k) {
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > k) {
            res += (a[i] - k + b[i] - 1) / b[i];
        }
    }
    return res <= m;
}

void solve() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) std::cin >> a[i] >> b[i];
    int l = 0, r = 1e6 + 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    ll ans = 0, now = 0, cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > l) {
            now = (a[i] - l + b[i] - 1) / b[i], cnt += now;
            ans += sum(a[i], now, b[i]);
        }
    }
    std::cout << ans + ll(l * (m - cnt));
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
