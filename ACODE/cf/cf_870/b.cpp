#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int ok = 1;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    for (int i = 0; i < n / 2; ++i) {
    	if (a[i] != a[n - i - 1]) {
            ok = 0;
            break;
        }
    }

    int ans = 0;
    for (int i = 0; i < n / 2; ++i) {
        int d = a[i] - a[n - i - 1];
        ans = std::__gcd(ans, abs(d));
    }

    if (ok) std::cout << "0\n";
    else std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
