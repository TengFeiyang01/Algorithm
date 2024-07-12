#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
ll L[2025]{0};
ll R[2025]{0};


void solve() {
    int n;
    std::cin >> n;
    ll ans = 0;

    int deep = 0;
    for (int i = 1; i <= n; ++i) {
        if (L[i] <= n and n <= R[i]) {
            deep = i;
            break;
        }
    }
    int l = n, r = n;

    int d = n - L[deep];
    int p = R[deep] - n;

    for (int i = deep; i >= 1; --i) {
        for (int x = l; x <= r; ++x) {
            ans += 1LL * x * x;
        }
        if (d > 0) {
            d -= 1;
        }
        if (p > 0) {
            p -= 1;
        }
        l = std::max(L[i - 1] + d, L[i - 1]);
        r = std::min(R[i - 1], R[i - 1] - p);
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    for (ll i = 1, cur = 1; i <= 2025; ++i) {
        L[i] = cur;
        R[i] = cur + i - 1;
        cur += i;
    }

    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
