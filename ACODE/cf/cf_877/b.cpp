#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> b;
    int p;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] == n) p = i;
        if (a[i] == 1 or a[i] == 2 or a[i] == n) b.push_back(i);
    }
    std::sort(b.begin(), b.end());
    std::cout << b[1] + 1 << " " << p + 1 << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
