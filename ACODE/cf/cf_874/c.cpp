#include <bits/stdc++.h>


void solve() {
    int n, odd = 0, even = 0;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] % 2) {
            odd++;
        } else {
            even++;
        }
    }
    std::sort(a.begin(), a.end());
    if (a[0] % 2 == 0 and odd) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
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
