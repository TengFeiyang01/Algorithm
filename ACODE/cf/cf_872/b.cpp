#include <bits/stdc++.h>

using ll = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<ll> a(n * m);
    for (int i = 0; i < n * m; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
	ll mi1 = a[0], mi2 = a[1];
    ll mx1 = a[n * m - 1], mx2 = a[n * m - 2];

    if (n > m) {
        ll ans1 = ((mx1 - mi1) * (n - 1) * m + (mx1 - mi2) * (m - 1));
        ll ans2 = ((mx1 - mi1) * (n - 1) * m + (mx2 - mi1) * (m - 1));
        std::cout << std::max(ans1, ans2) << "\n";
    } else {
        ll ans1 = ((mx1 - mi1) * (m - 1) * n + (mx1 - mi2) * (n - 1));
        ll ans2 = ((mx1 - mi1) * (m - 1) * n + (mx2 - mi1) * (n - 1));
        std::cout << std::max(ans1, ans2) << "\n";
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
